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
echo "map <F2> <c-w><c-w>" >> ~/.vimrc
export MAIL="hyojang@student.42seoul.kr"
#alias cc="gcc -Werror -Wall -Wextra"
#alias norm="norminette"

# Stdheader
#mkdir -p ~/.vim/plugin
#cp stdheader.vim ~/.vim/plugin/
#if [ ! -z "$USER" ]
#then
#    echo "USER=`/usr/bin/whoami`" >> ~/.zshrc
#    echo "export USER" >> ~/.zshrc
#fi
#
#if [ ! -z "$GROUP" ]
#then
#    echo "GROUP=`/usr/bin/id -gn $user`" >> ~/.zshrc
#    echo "export GROUP" >> ~/.zshrc
#fi

#brew
#rm -rf $HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew && echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc && source $HOME/.zshrc && brew update
#brew install readline
