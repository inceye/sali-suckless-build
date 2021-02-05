/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nogroup";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "black",     /* after initialization */
	[INPUT] =  "#005577",   /* during input */
	[FAILED] = "#CC3333",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0;

/* default message */
static const char * message = "Shoo! Go away!";

/* indicate password length with '*' */
#define PWDIND

/* text color */
static const char * text_color = "#fce94f";

/* text size (must be a valid size) */
static const char * font_name = "-misc-dejavu sans mono-medium-r-normal--0-0-0-0-m-0-iso8859-1";

/* time in seconds before the monitor shuts down */
static const int monitortime = 10;

/* use a screenshot instead of just color */
#define DOSCROT
/*Enable blur*/
#define BLUR
/*Set blur radius*/
static const int blurRadius=20;
/*Enable Pixelation*/
//#define PIXELATION
/*Set pixelation radius*/
static const int pixelSize=0;

/* time in seconds to cancel lock with mouse movement */
static const int timetocancel = 4;
