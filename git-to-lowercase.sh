#!/bin/bash

# TODO: Delete this file
# Only needed for forcing directories and files to 
# lowercase

to_lowercase() {
    basename $1 
}

export -f to_lowercase

find . \
  -not -path "./git-to-lowercase*" \
  -not -path "." \
  -not -path "./.git*" \
  -not -path "./.vscode*" \
  -not -path "./Makefile" \
  -not -path "./README.md" \
  -not -path "./catch_*" \
  -exec bash -c 'to_lowercase "$0"' {} \;

