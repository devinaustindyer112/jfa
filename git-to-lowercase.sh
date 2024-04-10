#!/bin/bash

# TODO: Move this file
# Only needed for forcing directories and files to lowercase

# TODO: Research why OS being case insensitive causes discrepencies
# https://stackoverflow.com/questions/3011625/git-mv-and-only-change-case-of-directory

# QUESTION: How do people normally style bash?

to_lowercase() {
    echo $1 | tr '[:upper:]' '[:lower:]'
}

export -f to_lowercase

echo "------- rename directories -------"

# Rename directories
directories=($(git ls-tree -r -d --name-only HEAD | uniq ))
index=$(( ${#directories[@]} -1 ))

while (( index >= 0 ))
do
    echo "$(to_lowercase ${directories[index]} )"
    (( index-- ))
done

echo "------- rename files -------"

# Rename files
files=($(git ls-files | uniq | grep -v 'Makefile\|README.md'))
for file in "${files[@]}"
do
    echo "$(to_lowercase $file)"
done
