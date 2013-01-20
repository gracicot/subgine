#!/bin/bash
rm -fr /usr/local/include/subgine
rsync -av --include "*/" --include "*.h" --include "*.hpp" --exclude "*" --exclude "build/" --exclude ".git/" --exclude ".svn/" /home/master/prog/subgine/. /usr/local/include/subgine/
#sed -i 's/\ \"/\ \<subgine\//g' /usr/local/include/subgine/*.hpp
#sed -i 's/.h\"/.h\>/g' /usr/local/include/subgine/*.hpp
#sed -i 's/.hpp\"/.hpp\>/g' /usr/local/include/subgine/*.hpp