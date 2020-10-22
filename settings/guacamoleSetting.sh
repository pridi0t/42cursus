rm -rf ~/.vimrc
touch ~/.vimrc
echo "if has(\"syntax\")" >> ~/.vimrc
echo "	syntax on" >> ~/.vimrc
echo "endif" >> ~/.vimrc
echo "set hlsearch" >> ~/.vimrc
echo "set nu" >> ~/.vimrc
echo "set autoindent" >> ~/.vimrc
echo "set cindent" >> ~/.vimrc
echo "set showmatch" >> ~/.vimrc
