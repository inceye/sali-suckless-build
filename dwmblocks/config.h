//Modify this file to change what commands output to your statusbar, and recompile using the make command.

static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"🔊", "pamixer --get-volume-human",	5,	10},
	{"🎹", "xkblayout-state print '%n'",	1,	0},
	{"💾", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	10,	0},
	{"🌡", "cputemp",	5,	0},
	{"🌡", "gputemp",	5,	0},
	{"📁/", "df -h \"/\" | grep \"/\" | awk '{print $4}'",	10,	0},
	{"📁~", "df -h \"/home\" | grep \"/home\" | awk '{print $4}'",	10,	0},
	{"📁#", "df -h \"/home/archive\" | grep \"/home/archive\" | awk '{print $4}'",	10,	0},
	//{"", "cat /etc/status/pipes/battery | cut -d ' ' -f 3",	10,		0},
	{"📅", "date '+%Y-%m-%d(%a)'",	5,	0},
	{"⌚", "date '+%I:%M:%S%p'",	1,	0},
};
//Sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char *delim = " ";

// Have dwmblocks automatically recompile and run when you edit this file in
// vim with the following line in your vimrc/init.vim:

// autocmd BufWritePost ~/.local/src/dwmblocks/config.h !cd ~/.local/src/dwmblocks/; sudo make install && { killall -q dwmblocks;setsid dwmblocks & }
