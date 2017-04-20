#!/usr/bin/env python
import os, re

s = """
CC=g++ -std=c++11 -Wall -Llib -Iinclude -lstdc++
EXFLAGS=-Wl,-rpath=./lib
SOFLAGS=-shared -fPIC

"""

srcfiles = os.listdir('src/')
binsrc, binfiles, libfiles = [], [], {}
for f in srcfiles:
    if re.match('[0-9]{3}', f):
        binsrc.append('src/' + f)
        binfiles.append('bin/' + re.sub('\..*', '', f))
    else:
        k = re.sub('\..*', '', f)
        libfiles[k] = ('src/' + f, 'lib/lib' + k + '.so')

s += "all: " + ' '.join(binfiles) + "\n\n"
s += "clean:\n\trm -r bin lib\n\n"
s += "bin/:\n\tmkdir -p bin\n\n"
s += "lib/:\n\tmkdir -p lib\n\n"

for srcname, binname in zip(binsrc, binfiles):
    deps = []
    with open(srcname) as fo:
        for line in fo:
            match = re.search('#include "(.*)\.h"', line)
            if match:
                deps.append(match[1])
    s += binname + ": " + srcname + ' '
    s += ' '.join(libfiles[dep][1] for dep in deps)
    s += ' | bin/\n\t'

    s += '$(CC) $(EXFLAGS) ' + srcname + ' -o ' + binname + ' '
    s += ' '.join('-l' + dep for dep in deps)
    s += '\n\n'

for k in libfiles:
    srcname, libname = libfiles[k]
    deps = []
    with open(srcname) as fo:
        for line in fo:
            match = re.search('#include "(.*)\.h"', line)
            if match and match[1] != k:
                deps.append(match[1])
    s += libname + ": " + srcname + ' '
    s += ' '.join(libfiles[dep][1] for dep in deps)
    s += ' | lib/\n\t'

    s += '$(CC) $(SOFLAGS) ' + srcname + ' -o ' + libname + ' '
    s += ' '.join('-l' + dep for dep in deps)
    s += '\n\n'

open('makefile', 'w').write(s)
