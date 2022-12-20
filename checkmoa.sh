#!/bin/bash
# Test all testers

#libft_folder="$HOME/42/tronc/libft"
libft_folder="."

# Check if folder exists
if [ -d "$libft_folder" ]; then
	echo "directory \"$libft_folder\" exists, continuing"
else
	exit 2
fi

# Check forbidden functions
grep -E "[^\/]\s+printf" "$libft_folder"/ft*.c

# Init
if [ ! -d "$libft_folder/libftTester" ]; then
	echo "directory \"$libft_folder/libftTester\"does not exists"
	git clone https://github.com/Tripouille/libftTester.git
fi
if [ ! -d "$libft_folder/libft-war-machine" ]; then
	echo "directory \"$libft_folder/libft-war-machine\"does not exists"
	git clone https://github.com/0x050f/libft-war-machine
fi
if [ ! -d "$libft_folder/libft-unit-test" ]; then
	echo "directory \"$libft_folder/libft-unit-test\"does not exists"
	git clone https://github.com/alelievr/libft-unit-test.git
fi

case "$1" in
	ft_*)
		to_test=$1
	;;
	*)
		to_test=""
	;;
esac

#new=$(echo "$to_test" | sed "s/^ft_\(.*\)\\(\.c\)/\1/")
new=$(echo "$to_test" | sed "s/^ft_\(.*\)/\1/")

## Launch testers
# War machine
./libft-war-machine/grademe.sh "$to_test"

# Tripouille tester
cd libftTester/ || exit 2
if [[ -n "$1" ]]; then
	echo "$to_test"
	make "$new" | grep "$to_test"
	#make "$new"
else
	make a
fi

# Unit test
cd ../libft-unit-test || exit 2
if [[ -n "$1" ]]; then
	make f | grep -i "$to_test"
else
	make f
fi

# Cleanup
cd ../
make fclean
