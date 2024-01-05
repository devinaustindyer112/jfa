#!/bin/bash

# TODO: Delete this file
# Only needed for forcing directories and files to lowercase

to_lowercase() {
    echo $1 | tr '[:lower:]' '[:upper:]'
}

export -f to_lowercase

# TODO: Research why OS being case insensitive causes discrepencies
# https://stackoverflow.com/questions/3011625/git-mv-and-only-change-case-of-directory


# handle renaming files fist
git ls-files | uniq | grep -v 'Makefile\|README.md'| while read -r file; do echo "$file"; done

# handle renaming directories first. this will be a 2 step process
git ls-tree -r -d --name-only HEAD | uniq | while read -r directory; do echo "$directory"; done



