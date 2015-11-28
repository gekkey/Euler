#!/usr/bin/env ruby
s = <<-SH
CC=g++ -std=c++11 -Wall -Llib -Iinclude -lstdc++
EXFLAGS=-Wl,-rpath=./lib
SOFLAGS=-shared -fPIC

_all: all
bin:
	mkdir bin
lib:
	mkdir lib

SH

srcfiles = Dir['*.cpp'].map {|filename| filename[0...-4]}

binsrc = srcfiles.select {|filename| filename.match(/[0-9]{3}/)}
libsrc = srcfiles.reject {|filename| filename.match(/[0-9]{3}/)}

binfiles = binsrc.map {|filename| 'bin/' + filename.match(/0*(.*)/)[1]}
libfiles = libsrc.map {|filename| 'lib/lib' + filename.match(/([^0-9]*)/)[1] + '.so'}

s << "all: " + binfiles.join(' ') + "\n\n"
s << "clean:\n\trm -r bin lib\n\n"

binfiles.each_with_index do |filename, i|
  deps = []
  File.open(binsrc[i] + ".cpp", "r").each_line do |line|
    if line.start_with?('#include "')
      deps << line.match(/"(.*)\.h"/)[1]
    end
  end
  s << filename + ": " + binsrc[i] + ".cpp "
  s << deps.map {|dep| "lib/lib" + dep + ".so"} .join(' ')
  s << "| bin\n\t"
  s << '$(CC) $(EXFLAGS) ' + binsrc[i] + '.cpp -o ' + filename + ' '
  s << deps.map {|dep| '-l' + dep} .join(' ')
  s << "\n\n"
end

libfiles.each_with_index do |filename, i|
  deps = []
  File.open(libsrc[i] + ".cpp", "r").each_line do |line|
    if line.start_with?('#include "')
      dep = line.match(/"(.*)\.h"/)[1]
      deps << dep unless dep == libsrc[i]
    end
  end
  s << filename + ": " + libsrc[i] + ".cpp "
  s << deps.map {|dep| "lib/lib" + dep + ".so"} .join(' ')
  s << "| lib\n\t"
  s << '$(CC) $(SOFLAGS) ' + libsrc[i] + '.cpp -o ' + filename + ' '
  s << deps.map {|dep| '-l' + dep} .join(' ')
  s << "\n\n"
end

File.open('makefile', 'w').write(s)
