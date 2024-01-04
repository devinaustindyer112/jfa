#!/bin/bash

# TODO: Delete this file
# Only needed for forcing directories and files to 
# lowercase

to_lowercase() {
    echo $1 | tr '[:lower:]' '[:upper:]'
}

export -f to_lowercase

# TODO: Incorporate the following command instead of find
# echo 'hi' | git ls-files | grep -E '\.hpp$|\.cpp$|/$'


git ls-files | xargs -n 1 dirname | uniq | while read -r directory; do echo "$directory"; done


git ls-files -o -d | grep '/$'


