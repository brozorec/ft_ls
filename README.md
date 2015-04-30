ft_ls

Reproduction of the UNIX Command "ls" (list directory contents) in C with the following options:
-a      - do not ignore entries starting with .
-R      - list subdirectories recursively
-r      - reverse order while sorting
-t      - sort by modification time, newest first
-l      - use a long listing format
-g      - like -l, but do not list owner
-o      - like -l, but do not list group information
-@      - show ACL permissions


Usage:
-> make
-> ./ft_ls [option] [file]
