/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMINAL "st"
#define TERMCLASS "St"

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 15;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 15;       /* vert inner gap between windows */
static const unsigned int gappoh    = 20;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 20;       /* vert outer gap between windows and screen edge */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char buttonbar[]       = "⋮";
static const int user_bh            = 30;       /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const int vertpad            = 10;       /* vertical padding of bar */
static const int sidepad            = 10;       /* horizontal padding of bar */
static const char *fonts[]          = { "DejaVu Sans Mono:size=13", "JoyPixels:pixelsize=10:antialias=true:autohint=true"  };
static char dmenufont[]             = "DejaVu Sans Mono:size=13";
static char normbgcolor[]           = "#003060";
static char normbordercolor[]       = "#003060";
static char normfgcolor[]           = "#cccccc";
static char selfgcolor[]            = "#ffffff";
static char selbordercolor[]        = "#707020";
static char selbgcolor[]            = "#104840";
static const unsigned int baralpha = 0xb0;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3] = {
    /*               fg           bg           border   */
    [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
    [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

typedef struct {
    const char *name;
    const void *cmd;
} Sp;
const char *spcmd1[] = {TERMINAL, "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {TERMINAL, "-n", "spcalc", "-f", "monospace:size=16", "-g", "50x20", "-e", "bc", "-lq", NULL };
static Sp scratchpads[] = {
    /* name          cmd  */
    {"spterm",      spcmd1},
    {"spranger",    spcmd2},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class    instance      title       	 tags mask    isfloating   isterminal  noswallow  monitor */
    { "Gimp",     NULL,       NULL,       	    0,            0,           0,         0,        -1 },
    { TERMCLASS,   NULL,      NULL,       	    0,            0,           1,         0,        -1 },
    { NULL,       NULL,       "Event Tester",   0,            0,           0,         1,        -1 },
    { NULL,       NULL,       "Video Receive",  0,            0,           0,         1,        -1 },
    { NULL,       NULL,       "Video Preview",  0,            0,           0,         1,        -1 },
    { NULL,      "spterm",    NULL,       	    SPTAG(0),     1,           1,         0,        -1 },
    { NULL,      "spcalc",    NULL,       	    SPTAG(1),     1,           1,         0,        -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#define WARP_CURSOR 1 /* warp cursor to the middle of window on focus */
#define NO_WARP_ON_CONFIG 1 /* don't warp if focus did not change */
#define WARP_ON_LAYOUT 0 /* Warp on layout change if window shifted off */
#define WARP_ON_VIEW 0 /* Warp on view change */
#include "vanitygaps.c"
static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",	tile },			/* Default: Master on left, slaves on right */
    { "TTT",	bstack },		/* Master on top, slaves on bottom */

    { "[@]",	spiral },		/* Fibonacci spiral */
    { "[\\]",	dwindle },		/* Decreasing in size right and leftward */

    { "[M]",	monocle },		/* All windows on top of eachother */
    { "H[]",	deck },			/* Master on left, slaves in monocle-like mode on right */

    { "|M|",	centeredmaster },		/* Master in middle, slaves on sides */
    { ">M>",	centeredfloatingmaster },	/* Same but master floats */

    { "###",    grid },

    { "><>",	NULL },			/* no layout function means floating behavior */
    { NULL,		NULL },
};

// If you wish to use the default tag settings for new tags instead of
// current monitor settings, set START_DEFAULT to 1. With START_DEFAULT
// set to 0 if you for example have your layout on 1st tag set to 
// deck and you have not used 1+2 tag before, if you toggle 2nd tag,
// your layout will automatically be deck
#define START_DEFAULT 0 
// With START_DEFAULT set to 1 you have to define default_tag
static const TagTree default_tag = 
{ 0,    - 1,    nmaster,    mfact,      showbar,   0,   gappih, gappiv, gappoh, gappov };

// Settings that will be applied on startup or on tagdefaults call
static const TagTree tags_defaults[] = {
    /*  tag monitor nmaster     mfact       showbar     layout  ih      iv      oh      ov gaps*/
    { ~0,   - 1,    nmaster,    mfact,      0,          8,  gappih, gappiv, gappoh, gappov },
    { 1,    - 1,    nmaster,    mfact,      showbar,    0,  gappih, gappiv, gappoh, gappov },
    { 2,    - 1,    nmaster,    mfact,      showbar,    0,  gappih, gappiv, gappoh, gappov },
    { 4,    - 1,    nmaster,    mfact,      showbar,    0,  gappih, gappiv, gappoh, gappov },
    { 8,    - 1,    nmaster,    mfact,      showbar,    0,  gappih, gappiv, gappoh, gappov },
    { 16,   - 1,    nmaster,    mfact,      showbar,    0,  gappih, gappiv, gappoh, gappov },
    { 32,   - 1,    nmaster,    mfact,      showbar,    0,  gappih, gappiv, gappoh, gappov },
    { 64,   - 1,    nmaster,    mfact,      showbar,    0,  gappih, gappiv, gappoh, gappov },
    { 128,  - 1,    nmaster,    mfact,      showbar,    0,  gappih, gappiv, gappoh, gappov },
    { 256,  - 1,    nmaster,    mfact,      showbar,    0,  gappih, gappiv, gappoh, gappov },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
        { MODKEY,                       KEY,    view,           {.ui = 1 << TAG} }, \
        { MODKEY|ControlMask,           KEY,    toggleview,     {.ui = 1 << TAG} }, \
        { MODKEY|ShiftMask,             KEY,    tag,            {.ui = 1 << TAG} }, \
        { MODKEY|ControlMask|ShiftMask, KEY,    toggletag,      {.ui = 1 << TAG} }, 
#define STACKKEYS(MOD,ACTION) \
        { MOD,	                        XK_j,   ACTION##stack,	{.i = INC(+1) } }, \
        { MOD,	                        XK_k,   ACTION##stack,	{.i = INC(-1) } }, \
        { MOD,                          XK_v,   ACTION##stack,  {.i = 0 } }, 
#define MOVEKEYS(MOD,ACTION) \
        { MOD,	                        XK_h,	ACTION##stack,	{.i = INC(+1) } }, \
        { MOD,	                        XK_l,	ACTION##stack,	{.i = INC(-1) } }, 
/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, "-l", "10", "-i", NULL };
static const char *termcmd[]  = { TERMINAL, NULL };
static const char *layoutmenu_cmd = "layoutmenu.sh";

#include <X11/XF86keysym.h>
#include "shiftview.c"
static Key keys[] = {
    /* modifier			    key		        function	    argument         */

    /*************************************************************************/
    /*                             TAG KEYS                                  */
    /*************************************************************************/
    STACKKEYS(MODKEY,			            focus)
    MOVEKEYS(MODKEY,			            push)

    TAGKEYS(			    XK_1,		                    0)
    TAGKEYS(			    XK_2,		                    1)
    TAGKEYS(			    XK_3,		                    2)
    TAGKEYS(			    XK_4,		                    3)
    TAGKEYS(			    XK_5,		                    4)
    TAGKEYS(			    XK_6,		                    5)
    TAGKEYS(			    XK_7,		                    6)
    TAGKEYS(			    XK_8,		                    7)
    TAGKEYS(			    XK_9,		                    8)

    { MODKEY,			    XK_0,		    view,		    {.ui = ~0 } },
    { MODKEY|ShiftMask,		XK_0,		    tag,		    {.ui = ~0 } },

    { MODKEY,			    XK_Tab,		    view,		    {0} },
    { MODKEY,			    XK_backslash,	view,		    {0} },

    { MODKEY,			    XK_g,		    shiftview,	    { .i = -1 } },
    { MODKEY|ShiftMask,		XK_g,		    shifttag,	    { .i = -1 } },
    { MODKEY,			    XK_semicolon,	shiftview,	    { .i = 1 } },
    { MODKEY|ShiftMask,		XK_semicolon,	shifttag,	    { .i = 1 } },

    { MODKEY,			    XK_Page_Up,	    shiftview,	    { .i = -1 } },
    { MODKEY|ShiftMask,		XK_Page_Up,	    shifttag,	    { .i = -1 } },
    { MODKEY,			    XK_Page_Down,	shiftview,	    { .i = +1 } },
    { MODKEY|ShiftMask,		XK_Page_Down,	shifttag,	    { .i = +1 } },

    { MODKEY|ShiftMask,     XK_v,           winview,        {0} },

    /*************************************************************************/
    /*                           MONITOR KEYS                                */
    /*************************************************************************/

    { MODKEY|ControlMask,	XK_j,	        focusmon,	    {.i = -1 } },
    { MODKEY|ControlMask,	XK_k,	        focusmon,	    {.i = +1 } },
    { MODKEY|ControlMask,	XK_h,	        tagmon,		    {.i = -1 } },
    { MODKEY|ControlMask,	XK_l,	        tagmon,		    {.i = +1 } },

    { MODKEY,			    XK_Left,	    focusmon,	    {.i = -1 } },
    { MODKEY|ShiftMask,		XK_Left,	    tagmon,		    {.i = -1 } },
    { MODKEY,			    XK_Right,	    focusmon,	    {.i = +1 } },
    { MODKEY|ShiftMask,		XK_Right,	    tagmon,		    {.i = +1 } },

    { MODKEY,			    XK_s,		    togglesticky,	{0} },
    { MODKEY,			    XK_space,	    zoom,		    {0} },

    /*************************************************************************/
    /*                             QUIT KEYS                                 */
    /*************************************************************************/
    { MODKEY,			    XK_Escape,	    spawn,		    SHCMD("sysact") },
    { MODKEY|ShiftMask,		XK_Escape,	    spawn,		    SHCMD("sysact") },
    { MODKEY,			    XK_BackSpace,	spawn,		    SHCMD("sysact") },
    { MODKEY|ShiftMask,		XK_BackSpace,	spawn,		    SHCMD("sysact") },
    { MODKEY|ControlMask,	XK_q,		    spawn,		    SHCMD("sysact") },

    { MODKEY|ShiftMask,		XK_q,		    killclient,	    {0} },

    /*************************************************************************/
    /*                            LAYOUT KEYS                                */
    /*************************************************************************/
    { MODKEY,			    XK_t,		    setlayout,	    {.v = &layouts[0]} }, /* tile */
    { MODKEY|ShiftMask,		XK_t,		    setlayout,	    {.v = &layouts[1]} }, /* bstack */
    { MODKEY,			    XK_y,		    setlayout,	    {.v = &layouts[4]} }, /* monocle */
    { MODKEY|ShiftMask,		XK_y,		    setlayout,	    {.v = &layouts[5]} }, /* deck */
    { MODKEY,			    XK_u,		    setlayout,	    {.v = &layouts[6]} }, /* centeredmaster */
    { MODKEY|ShiftMask,		XK_u,		    setlayout,	    {.v = &layouts[8]} }, /* centeredfloatingmaster */
    { MODKEY|ShiftMask,		XK_f,		    setlayout,	    {.v = &layouts[9]} }, /* all floating */

    { MODKEY|ShiftMask,		XK_space,	    togglefloating,	{0} },
    { MODKEY,			    XK_f,		    togglefullscr,	{0} },

    { MODKEY,			    XK_i,		    incnmaster,     {.i = +1 } },
    { MODKEY|ShiftMask,		XK_i,		    incnmaster,     {.i = -1 } },

    /*************************************************************************/
    /*                            STYLE KEYS                                 */
    /*************************************************************************/
    { MODKEY,			    XK_z,		    incrgaps,	    {.i = +3 } },
    { MODKEY,			    XK_x,		    incrgaps,	    {.i = -3 } },
    { MODKEY,			    XK_a,		    togglegaps,	    {0} },
    { MODKEY|ShiftMask,		XK_a,		    defaultgaps,	{0} },

    { MODKEY|ShiftMask,		XK_h,		    setmfact,	    {.f = -0.05} },
    { MODKEY|ShiftMask,		XK_l,		    setmfact,      	{.f = +0.05} },

    { MODKEY,			    XK_b,		    togglebar,	    {0} },

    /*************************************************************************/
    /*                            VOLUME KEYS                                */
    /*************************************************************************/
    { MODKEY,			    XK_minus,	    spawn,		    SHCMD("pamixer --allow-boost -d 5; kill -44 $(pidof dwmblocks)") },
    { MODKEY|ShiftMask,		XK_minus,	    spawn,		    SHCMD("pamixer --allow-boost -d 15; kill -44 $(pidof dwmblocks)") },
    { MODKEY,			    XK_equal,	    spawn,		    SHCMD("pamixer --allow-boost -i 5; kill -44 $(pidof dwmblocks)") },
    { MODKEY|ShiftMask,		XK_equal,	    spawn,		    SHCMD("pamixer --allow-boost -i 15; kill -44 $(pidof dwmblocks)") },
    { MODKEY,			    XK_m,		    spawn,		    SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },

    /*************************************************************************/
    /*                              MPC KEYS                                 */
    /*************************************************************************/
    { MODKEY,			    XK_p,			spawn,		    SHCMD("mpc toggle") },
    { MODKEY|ShiftMask,		XK_p,			spawn,		    SHCMD("mpc pause ; pauseallmpv") },
    { MODKEY,			    XK_bracketleft,	spawn,		    SHCMD("mpc seek -10") },
    { MODKEY|ShiftMask,		XK_bracketleft,	spawn,		    SHCMD("mpc seek -60") },
    { MODKEY,			    XK_bracketright,spawn,		    SHCMD("mpc seek +10") },
    { MODKEY|ShiftMask,		XK_bracketright,spawn,		    SHCMD("mpc seek +60") },
    { MODKEY,			    XK_comma,	    spawn,		    SHCMD("mpc prev") },
    { MODKEY|ShiftMask,		XK_comma,	    spawn,		    SHCMD("mpc seek 0%") },
    { MODKEY,			    XK_period,	    spawn,		    SHCMD("mpc next") },
    { MODKEY|ShiftMask,		XK_period,	    spawn,		    SHCMD("mpc repeat") },

    /*************************************************************************/
    /*                             SPAWN KEYS                                */
    /*************************************************************************/
    { MODKEY,			    XK_Return,	    spawn,		    {.v = termcmd } },
    { MODKEY,			    XK_d,		    spawn,          {.v = dmenucmd } },

    { MODKEY,			    XK_grave,	    spawn,	        SHCMD("dmenuunicode") },
    { MODKEY,			    XK_w,		    spawn,		    SHCMD("$BROWSER") },
    { MODKEY,			    XK_o,			spawn,		    SHCMD("dmenupass") },
    { MODKEY,			    XK_r,			spawn,		    SHCMD(TERMINAL " -e ranger") },
    { MODKEY,			    XK_e,			spawn,		    SHCMD(TERMINAL " -e ranger ~/Downloads/Surf") },
    { MODKEY,			    XK_apostrophe,	togglescratch,	{.ui = 1} },
    { MODKEY|ShiftMask,		XK_Return,	    togglescratch,	{.ui = 0} },

    /*************************************************************************/
    /*                           SCREEN CAPTURE                              */
    /*************************************************************************/
    { MODKEY,				XK_c,	        spawn,		    SHCMD("scrot -m \"$HOME/Pictures/Screenshots/%s_%Y-%m-%d_%H:%M:%S_\\$wx\\$h.png\"")},
    { MODKEY|ShiftMask,		XK_c,	        spawn,		    SHCMD("scrot -s \"$HOME/Pictures/Screenshots/%s_%Y-%m-%d_%H:%M:%S_\\$wx\\$h.png\" -e 'mogrify -crop 10000x10000+1+1 $f'")},
    { 0,				    XK_Print,	    spawn,		    SHCMD("scrot -m \"$HOME/Pictures/Screenshots/%s_%Y-%m-%d_%H:%M:%S_\\$wx\\$h.png\"")},
    { MODKEY,			    XK_Print,	    spawn,		    SHCMD("scrot -s \"$HOME/Pictures/Screenshots/%s_%Y-%m-%d_%H:%M:%S_\\$wx\\$h.png\" -e 'mogrify -crop 10000x10000+1+1 $f'")},

    /*************************************************************************/
    /*                            SPECIAL KEYS                               */
    /*************************************************************************/
    { 0, XF86XK_AudioMute,		            spawn,		    SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
    { 0, XF86XK_AudioRaiseVolume,	        spawn,		    SHCMD("pamixer --allow-boost -i 3; kill -44 $(pidof dwmblocks)") },
    { 0, XF86XK_AudioLowerVolume,	        spawn,		    SHCMD("pamixer --allow-boost -d 3; kill -44 $(pidof dwmblocks)") },
    { 0, XF86XK_AudioPrev,		            spawn,		    SHCMD("mpc prev") },
    { 0, XF86XK_AudioNext,		            spawn,		    SHCMD("mpc next") },
    { 0, XF86XK_AudioPause,		            spawn,		    SHCMD("mpc pause") },
    { 0, XF86XK_AudioPlay,		            spawn,		    SHCMD("mpc play") },
    { 0, XF86XK_AudioStop,		            spawn,		    SHCMD("mpc stop") },
    { 0, XF86XK_AudioRewind,	            spawn,		    SHCMD("mpc seek -10") },
    { 0, XF86XK_AudioForward,	            spawn,		    SHCMD("mpc seek +10") },
    { 0, XF86XK_AudioMedia,		            spawn,		    SHCMD(TERMINAL " -e ncmpcpp") },
    { 0, XF86XK_AudioMicMute,	            spawn,		    SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
    { 0, XF86XK_PowerOff,		            spawn,		    SHCMD("sysact") },
    { 0, XF86XK_Calculator,		            spawn,		    SHCMD(TERMINAL " -e bc -l") },
    { 0, XF86XK_Sleep,		                spawn,		    SHCMD("sudo -A zzz") },
    { 0, XF86XK_WWW,		                spawn,		    SHCMD("$BROWSER") },
    { 0, XF86XK_DOS,		                spawn,		    SHCMD(TERMINAL) },
    { 0, XF86XK_ScreenSaver,	            spawn,		    SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
    { 0, XF86XK_TaskPane,		            spawn,		    SHCMD(TERMINAL " -e htop") },
    { 0, XF86XK_Mail,		                spawn,		    SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks") },
    { 0, XF86XK_MyComputer,		            spawn,		    SHCMD(TERMINAL " -e lf /") },
    { 0, XF86XK_Launch1,		            spawn,		    SHCMD("xset dpms force off") },
    { 0, XF86XK_TouchpadToggle,	            spawn,		    SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
    { 0, XF86XK_TouchpadOff,	            spawn,		    SHCMD("synclient TouchpadOff=1") },
    { 0, XF86XK_TouchpadOn,		            spawn,		    SHCMD("synclient TouchpadOff=0") },
    { 0, XF86XK_MonBrightnessUp,           	spawn,		    SHCMD("xbacklight -inc 15") },
    { 0, XF86XK_MonBrightnessDown,	        spawn,		    SHCMD("xbacklight -dec 15") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
#ifndef __OpenBSD__
	{ ClkButton,		    0,		        Button1,	    spawn,		    {.v = dmenucmd } },
	{ ClkButton,		    0,		        Button3,	    spawn,		    SHCMD("sysact") },
	{ ClkLtSymbol,          0,              Button1,        togglevacant,   {0} },
	{ ClkLtSymbol,          0,              Button3,        layoutmenu,     {0} },
    { ClkWinTitle,          0,              Button1,        cursorwarp,     {0} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkWinTitle,          0,              Button4,        focusstack,     {- 1} },
    { ClkWinTitle,          0,              Button5,        focusstack,     {+ 1} },
    { ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
    { ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
    { ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
    { ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
    { ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
    { ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
#endif
    { ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD(TERMINAL " -e nvim ~/.local/src/dwmblocks/config.h") },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        winview,	    {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkClientWin,		    MODKEY,		    Button4,	    incrgaps,	    {.i = +1} },
    { ClkClientWin,		    MODKEY,		    Button5,	    incrgaps,	    {.i = -1} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
    { ClkTagBar,		    0,		        Button4,	    shiftview,	    {.i = -1} },
    { ClkTagBar,		    0,		        Button5,	    shiftview,	    {.i = 1} },
    { ClkRootWin,		    0,		        Button2,	    togglebar,	    {0} },
};
