# Plain Logger
Implementation of a simple logger that also provides with asynchronous way to create a dump of a given buffer.

## Prerequisites
* UNIX-based operating system with support for POSIX threads and signals.

## Description
In order to start logger, it is required to provide ``logger_start()`` with desired log filename and pointer to a buffer which is going to be dumped on demand along with it's size.

To log, ``logger_log()`` should be called with formatting string and it's arguments, just like in standard ``printf()``. All subsequent calls append a new line to log file with given information.

There are 3 (``LOG_MIN, LOG_STD, LOG_MAX``) levels of logged information that can be set by ``logger_set_level()``. Standard level will add current datetime with each logged line. Maxium level will additionally log filename, function name and line where ``logger_log()`` was called.

``logger_dump()`` is used to create a dump of previously given buffer. New file with current time and unique id is created in the working directory and filled with buffer contents. Creating a dump doesn't block calling thread and it completes in other thread.

After being done with logging, it is adviced to call ``logger_stop()`` which safely joins dump thread and zeros global structures.

## Files
* logger.c: Contains implementation of internal functions and thread methods that are not avilable to the end user.
* logger.h: Provides with library logger functions.
* main.c: Program demonstrating exemplary use of logger.

## Building
In order to build the logger along with sample program:
```
gcc logger.c main.c -o sample -lpthread
```