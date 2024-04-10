#!/bin/bash

# TODO: Move this file
# Only needed for forcing directories and files to lowercase

# TODO: Research why OS being case insensitive causes discrepencies
# https://stackoverflow.com/questions/3011625/git-mv-and-only-change-case-of-directory

# QUESTION: How do people normally style bash?

to_lowercase() {
    lowercase=$(echo "$1" | tr '[:upper:]' '[:lower:]')
    echo "$1 to $lowercase"
    
    git mv $1 "$1-tmp"
    git mv "$1-tmp" $lowercase
    git commit -m "$1 to $lowercase"
}

export -f to_lowercase

echo "------- rename directories -------"

# Rename directories
directories=($(git ls-tree -r -d --name-only HEAD | uniq ))
for directory in "${directories[@]}"
do
    echo "$(to_lowercase $directory)"
done

# echo "------- rename files -------"

# # Rename files
# files=($(git ls-files | uniq | grep -v 'Makefile\|README.md'))
# for file in "${files[@]}"
# do
#     echo "$(to_lowercase $file)"
# done
