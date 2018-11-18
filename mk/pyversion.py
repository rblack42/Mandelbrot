import os
import re
import sys

version_re = re.compile("^#define.*\"(.*)\"$")

VERSION = "include/version.h"

def main():
    vstring = "0.0.0"
    if os.path.isfile(VERSION):
        fin = open(VERSION,'r')
        lines = fin.readlines()
        lc = 0
        for l in lines:
            m = version_re.match(l)
            if m:
                vstring = m.group(1)
                break
            lc+=1
        fin.close()
    else:
        lines = []
        lines.append("#pragma once\n\n")
        lines.append("// Copyright 2018 Roie R. Black\n\n")
        lines.append("#define VERSION %s\n" % vstring)
        lc = 2
        vstring="0.0.0"
    major,minor,build = vstring.split('.')
    try:
        inc_opt = sys.argv[1]
    except:
        inc_opt = "build"
    if inc_opt == "version":
        print("Current version:",vstring)
        return
    if inc_opt == "major": major = str(int(major)+1)
    elif inc_opt == "minor": minor = str(int(minor)+1)
    else: build = str(int(build)+1)
    vstring = major + '.' + minor + "." + build

    fout = open(VERSION,'w')
    lines[lc] = "#define VERSION \"%s\"" % vstring
    for l in lines:
        fout.write(l)
    fout.close()

main()
