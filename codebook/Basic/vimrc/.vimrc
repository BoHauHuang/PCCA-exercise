syntax on
syntax enable
set et nu cin ls=2 ts=4 sw=4 sts=4 ttm=100
set number t_Co=256 mouse=a cursorline
colorscheme torte
hi CursorLine cterm=none ctermbg=DarkBlue ctermfg=none

nn <F4> :w ! cat -n \| lpr <CR>
nn <F7> :w <bar> :!vim %<_.in<left><left><left>
nn <F8> :w <bar> :!g++ % -o %< -std=c++11
\ -fsanitize=undefined -Wall -Wextra -Wshadow -DBANANA &&
\ for i in %<_*.in; do echo == && ./%< < $i; done <CR>
nn <F9> :w <bar> :!g++ % -o %< -std=c++11
\ -fsanitize=undefined -Wall -Wextra -Wshadow -DBANANA &&
\ echo == && ./%<