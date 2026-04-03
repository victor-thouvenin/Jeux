#!/bin/bash

[[ "Demineur.class" -ot "Demineur.java" ]] && { javac Demineur.java || exit 1; }; java Demineur $@