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
echo "set nofixendofline" >> ~/.vimrc
export MAIL="hyojang@student.42seoul.kr"
alias cc="gcc -Werror -Wall -Wextra"
alias norm="norminette"
