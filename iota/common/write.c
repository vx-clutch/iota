#include "write.h"
#include "../syslog/error.h"
#include "write.h"
#include <stdarg.h>
#include <stdio.h>
#include <sys/stat.h>

int
iota_write(char *path, char *src, ...)
{
	if (options.dry || options.verbose)
	{
		printf(" CREATE\t%s\n", path);
		return 0;
	}
	va_list args;
	va_start(args, src);
	FILE *fp;
	fp = fopen(path, "w");
	if (!fp)
		pfatalf("failed to open %s.", path);
	if (options.verbose || options.dry)
		printf(" CREATE\t%s\n", path);
	vfprintf(fp, src, args);
	fclose(fp);
	va_end(args);
	return 0;
}

struct stat st = { 0 };

int
iota_mkdir(char *path)
{
	if (stat(path, &st) != -1)
	{
		pwarningf("directory %s already exists", path);
		return 17; // TODO: use EEXIST
	}
	if (options.dry || options.verbose)
	{
		printf(" MKDIR\t%s\n", path);
		return 0;
	}
	int err = mkdir(path, 0700);
	if (err)
	{
		if (options.verbose || options.dry)
			printf(" MKDIR\t%s\n", path);
		pfatalf("failed to make directory at %s", path);
	}
	return 0;
}
