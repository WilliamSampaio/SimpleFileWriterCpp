#!/usr/bin/env bash
clear && \
    g++ -Werror -Wall main.cpp simplefilewriter.cpp -o simplefilewriter.out && \
    chmod +x simplefilewriter;
