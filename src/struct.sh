#! /bin/sh

trap "rm -f /tmp/struct*$$" EXIT HUP INT QUIT PIPE TERM

files=no

for i
do
	case $i in
	-*)	;;
	*)	files=yes
		;;
	esac
done

case $files in
yes)
	/usr/lib/struct/structure "$@" > /tmp/struct$$
	;;
no)
	cat > /tmp/structin$$
	/usr/lib/struct/structure /tmp/structin$$ "$@" > /tmp/struct$$
	;;
esac &&
	/usr/lib/struct/beautify < /tmp/struct$$
