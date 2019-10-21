#!/usr/bin/env python
import os, re
EXCLUDE_FILE_EXTENSIONS = (".swp",)

s = """\
CC=gcc
CXX=g++ -std=c++17 -lstdc++
CFLAGS+= -g -Wall -Werror -Llib -Iinclude
EXFLAGS=-Wl,-rpath=./lib
SOFLAGS=-shared -fPIC
.PRECIOUS: build/%.o

# Patterns
all: _all
clean:
	rm -rf ./bin ./lib ./build

test:
	python -c 'import unittest; from test import *; unittest.main()'

bin/ lib/ build/:
	mkdir -p $@

build/%.o: src/%.cpp | build/
	$(CXX) $(CFLAGS) $(EXFLAGS) $< -c -o $@

bin/%: src/%.cpp | bin/
	$(CXX) $(CFLAGS) $(EXFLAGS) $(if $(findstring lib/lib,$^),\\
		$(filter-out $<,$(patsubst lib/lib%.so,-l%,$^)),\\
		$<) -o $@

lib/lib%.so: src/%.cpp | lib/
	$(CXX) $(CFLAGS) $(SOFLAGS) $(patsubst lib/lib%.so,-l%,$^) -o $@

# Dependencies
"""

srcfiles = sorted(os.listdir('src/'))
binsrc, binfiles, libfiles = [], [], {}
for f in srcfiles:
    if re.search(".*(\..*)", f)[1] in EXCLUDE_FILE_EXTENSIONS:
        continue
    if re.match('[0-9]{3}', f):
        binsrc.append('src/' + f)
        binfiles.append('bin/' + re.sub('\..+', '', f))
    else:
        k = re.sub('\..*', '', f)
        libfiles[k] = ('src/' + f, 'lib/lib' + k + '.so')

s += "_all: " + ' '.join(binfiles) + "\n\n"

for srcname, binname in zip(binsrc, binfiles):
    deps = []
    with open(srcname) as fo:
        for line in fo:
            match = re.search('#include "(.*)\.h"', line)
            if match:
                deps.append(match[1])
    if not deps:
        continue
    srcname = re.sub('src/(.*)\.cpp', 'build/\\1.o', srcname)
    s += binname + ": " + srcname + ' '
    s += ' '.join(libfiles[dep][1] for dep in deps) + '\n'
s += '\n'

for k in libfiles:
    srcname, libname = libfiles[k]
    deps = []
    with open(srcname) as fo:
        for line in fo:
            match = re.search('#include "(.*)\.h"', line)
            if match and match[1] != k:
                deps.append(match[1])
    if not deps:
        continue
    s += libname + ": " + srcname + ' '
    s += ' '.join(libfiles[dep][1] for dep in deps) + '\n'

open('makefile', 'w').write(s)
