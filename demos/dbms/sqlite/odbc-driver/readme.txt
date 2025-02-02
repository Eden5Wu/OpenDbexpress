SQLite ODBC Driver
------------------

This is an open source ODBC driver for the wonderful
SQLite 2.8.* and SQLite 3.* Database Engine/Library.
The driver is usable but may contain lots of memory
leaks and all other kinds of bugs. Use it on your own
risk.

The current source can be downloaded from

    http://www.ch-werner.de/sqliteodbc/sqliteodbc-*.tar.gz

WIN32 binaries (the ODBC driver DLL, install/uninstall programs) are in

    http://www.ch-werner.de/sqliteodbc/sqliteodbc.exe

The binaries were made with SQLite 2.8.17, SQLite 3.7.8, MingW
cross compiler and tested on Windows NT 4.0 with the query tool
of MS Excel 97, with StarOffice 5.2 and OpenOffice 1.1 and 2.x.
Execute the sqliteodbc.exe NSIS installer to unpack the necessary
files. This installs the SQLite ODBC driver and creates a System DSN.
To remove the driver use the start menu entries or the UNINST.EXE
program. To create a SQLite data source use the ODBC control panel
applet and provide the name of the SQLite database file to be worked
on as an absolute pathname including the drive letter, eg as
"C:\TEMP\SQLite.DB". The busy (or lock) timeout for the database
can be specified in the respective field. If empty a default value
of 100000 milliseconds is used.

The Win64 installer (sqliteodbc_w64.exe) was made with SQLite 3.7.8,
MingW cross compiler and only rudimentary tested on Windows Vista 64.

Other tests were made on Linux with the "isql" command line tool
and the "DataManager" GUI tool of unixODBC 2.1.0.


Since October 14th, 2001, the driver supports the data types SQL_INTEGER,
SQL_TINYINT, SQL_SMALLINT, SQL_FLOAT, SQL_DOUBLE, SQL_DATE, SQL_TIME,
SQL_TIMESTAMP, and SQL_VARCHAR.

Since May 25th, 2002, SQL_LONGVARCHAR is available but rather
experimental. That type is used for SQLite schema containing text
or varchar with a size specifier larger than 255.

The data type mapping obtains per-column meta information from the
"PRAGMA table_info(...)" SQLite statement. If SELECTs are used which
contain columns for which the table qualifier cannot be determined,
no meta information for data type mapping is available and therefore
the database source data type will be SQL_VARCHAR or SQL_LONGVARCHAR
which usually maps to SQL_C_CHAR.

Restrictions of data type mapping:

- Integer and floating point columns in the database are reported
  as NULLs when no digit seen in the column, otherwise all digits
  up to end of string or non-digit are interpreted as the value,
  i.e. '10blurk' is ten, '0blurk' is zero, but 'blurk' is NULL.
- Format for SQL_DATE is YYYY-MM-DD or YYYYMMDD
- Format for SQL_TIME is hh:mm:ss or hhmmss
- Format for SQL_TIMESTAMP is
      YYYYMMDDhhmmss[fraction]
  or  YYYY-MM-DD hh:mm:ss[.fraction]
  or  hh:mm:ss[.fraction] YYYY-MM-DD
  The fractional part is expressed as 1E-09 seconds
- The driver puts the ODBC string representations for date/time,
  (eg for "{ts '2001-10-10 12:58:00'}" the substring within the
  single quotes) directly into the SQLite column


Since November 17th, 2001, configure/libtool is used for the Un*x
version which should automatically find the SQLite and unixODBC
(or iODBC) header files and libraries. Do the usual

    $ ./configure && make

followed by

    # make install

in order to get /usr/local/lib/libsqliteodbc.so.
Of course, you should have installed the unixODBC (or iODBC)
development RPMs since the ODBC header files are required for
the build of the SQLite ODBC driver.

Since May 15th, 2003, (version 0.51), there are two variants
of the SQLite 2.x driver for Win32 platforms: the first (sqliteodbc.dll)
linked against ISO8859-1 SQLite library exporting ODBC/SQL ANSI
functions, and the second (sqliteodbcu.dll) linked against UTF-8
SQLite library exporting ODBC/SQL UNICODE functions.

The UNICODE version is experimental and allows to turn off
wide character SQL data types by its configuration dialog
(checkmark labelled "No WCHAR"). It is known to work on Win32.
It may work on UN*X too using newer version of unixODBC.

To setup a SQLite data source using unixODBC (www.unixodbc.org):

  1. Add the driver to /etc/odbcinst.ini:

    [SQLite]
    Description=SQLite ODBC Driver
    Driver=/usr/local/lib/libsqliteodbc.so
    Setup=/usr/local/lib/libsqliteodbc.so
    Threading=2

  2. Add a DSN to your private ~/.odbc.ini:

    [mysqlitedb]
    Description=My SQLite test database
    Driver=SQLite
    Database=/home/johndoe/databases/mytest.db
    # optional lock timeout in milliseconds
    Timeout=2000

For iODBC (www.iodbc.org, only versions 3.0.[56] tested) do the
following steps:

  1. Add the driver to /etc/odbcinst.ini:

    [ODBC Drivers]
    ...
    SQLite=Installed
    ...

    [SQLite]
    Driver=/usr/local/lib/libsqliteodbc.so

  2. Add a DSN to your private ~/.odbc.ini:

    [ODBC Data Sources]
    ...
    mysqlitedb=SQLite
    ...

    [mysqlitedb]
    Driver=/usr/local/lib/libsqliteodbc.so
    Description=My SQLite test database
    Database=/home/johndoe/databases/mytest.db
    # optional lock timeout in milliseconds
    Timeout=2000


Python sample usage with eGenix mx-Extension
(see http://www.lemburg.com/files/python/mxODBC.html)

    $ python
    >>> import mx.ODBC.unixODBC
    >>> dbc=mx.ODBC.unixODBC.connect("mysqlitedb")
    >>> cur=dbc.cursor()
    >>> cur.execute("create table foo (id int, name string)")
    1
    >>> cur.execute("insert into foo values(1, 'Me')")
    1
    >>> cur.execute("insert into foo values(2, 'You')")
    1
    >>> dbc.commit()
    >>> cur.execute("select * from foo")
    >>> print cur.fetchall()
    [(1, 'Me'), (2, 'You')]
    >>> print cur.fetchall()
    []
    >>> cur.execute("drop table foo")
    1
    >>> dbc.commit()


Build instructions for MS Visual C++ 6.0:

... for SQLite 2.x.x

1. Extract the source tarball sqliteodbc.tar.gz
2. Extract the official SQLite 2.x.x sources in the sqliteodbc
   directory which resulted from step 1. Optionally, apply the
   sqlite-locale-patch-28* which matches your SQLite version
3. Setup your MSVC++ environment, ie PATH/INCLUDE/LIB, then
   open a command window, cd to the sqliteodbc directory and enter:

        nmake -f sqliteodbc.mak

   This compiles the SQLite sources first, creates a link library
   of the necessary object files, then compiles and links the ODBC
   driver and the (un)install program.
4. If you'd like to create the UNICODE version of the driver, enter:

  nmake -f sqliteodbc.mak clean
  nmake -f sqliteodbc.mak ENCODING=UTF8

... for SQLite 3.x.x

1. Extract the source tarball sqliteodbc.tar.gz
2. Extract the amalgamation SQLite 3.x.x. sources in the sqliteodbc
   directory which resulted from step 1.
3. Setup your MSVC++ environment, ie PATH/INCLUDE/LIB, then
   open a command window, cd to the sqliteodbc directory and enter:

        nmake -f sqlite3odbc.mak

   This compiles the amalgamation SQLite3 source and the ODBC driver
   first, then and links the ODBC driver and the (un)install program.


Names of Win32 Driver DLLs:

   sqliteodbc.dll    Driver with ISO8859-1 SQLite2 engine
   sqliteodbcu.dll   Driver with UTF-8/UNICODE SQLite2 engine
   sqlite3odbc.dll   Driver with SQLite3 engine


Build instructions for MingW cross compiler for Win32 targets:

  A script named mingw-cross-build.sh is provided which contains
  all necessary information. It downloads the required SQLite
  source tarballs and builds SQLite and the ODBC drivers. The
  final step is creating an NSIS installer.


Build instructions for MingW cross compiler for Win64 targets:

  A script named mingw64-cross-build.sh is provided which contains
  all necessary information. It downloads the required SQLite
  source tarballs and builds SQLite 3 and the ODBC driver. The
  final step is creating an NSIS installer.


Win32 install/remove/shell by RUNDLL32

  Each driver DLL provides entry points for ODBC driver installation
  and removal which can be invoked from RUNDLL32.EXE, eg

  ### install sqliteodbc.dll
  C:\> rundll32 [path]sqliteodbc.dll,install [quiet]

  ### remove sqlite3odbc.dll
  C:\> rundll32 [path]sqlite3odbc.dll,uninstall [quiet]

  If [path] is not provided newer Windows OSes tend to favor the
  sqlite*odbc*dll in system directories over the current directory,
  thus better provide an absolute path to the DLL of interest.
  If the word "quiet" appears anywhere after the DLL/function
  name, no info message boxes pop up (but errors are shown).

  An (interactive or batch) SQLite shell can be invoked, too, eg

  ### run SQLite shell on database C:\bla\my.db
  C:\> rundll32 [path]sqliteodbc.dll,shell C:\bla\my.db ...

  ### batch run with given SQL
  C:\> rundll32 [path]sqliteodbc.dll,shell -batch C:\bla\my.db
       "select * from table" <NUL: 2>NUL: >out.txt


Win64 notes

  On Win64 (64 bit versions of Vista, Windows 7) both 32 bit and 64 bit
  drivers can be installed in parallel. The 32 bit drivers are required
  when using 32 bit applications. In order to manage 32 bit data
  sources, the 32 bit ODBC admin tool C:\Windows\SysWOW64\odbcad32.exe
  must be used.


DSN-less connection to the driver

  Using the SQLDriverConnect() API it should be possible to connect to
  a SQLite database with these strings (Win32 and UN*X)

    DSN=SQLite Datasource;Database=full-path-to-db;...
    DSN=SQLite3 Datasource;Database=full-path-to-db;...

  alternatively

  Win32:

    Driver=SQLite ODBC Driver;Database=full-path-to-db;...
    Driver=SQLite3 ODBC Driver;Database=full-path-to-db;...

  UN*X (Linux RPM):

    Driver=SQLITE;Database=full-path-to-db;...
    Driver=SQLITE3;Database=full-path-to-db;...


Build Instructions for Alpha/Tru64 (OSF1 V5.1) and HP/UX (B.11.23 U ia64)

  Nikola Radovanovic had success with these commands to build
  all required components:

  sqlite (3.6.7):
    ./configure --prefix=$HOME/development --disable-tcl \
      CC='cc -pthread' CFLAGS='-DSQLITE_ENABLE_COLUMN_METADATA=1'
    gmake && gmake install

  unixODBC (2.2.12):
    ./configure --prefix=${HOME}/development --disable-gui \
      --without-x --enable-iconv=no
    gmake && gmake install

  sqliteodbc (>0.79):
    ./configure --with-sqlite3=${HOME}/development \
      --with-odbc=${HOME}/development --prefix=${HOME}/development \
      --enable-winterface=no
    OSF1:  gmake && gmake install
    HP/UX: gmake CFLAGS="+DD64" && gmake install


Build Instructions for RPM based systems

  rpmbuild -tb sqliteodbc-*.tar.gz


Build Instructions for Debian based systems

  tar xzf sqliteodbc-*.tar.gz
  cd sqliteodbc-*
  ./configure && make deb


Special build to use System.Data.SQLite on Win32/Win64

  A variant of the SQLite3 ODBC driver can be build which uses
  internal dynamic linking to System.Data.SQLite.dll or sqlite3.dll.
  This feature is turned on when running the mingw*-cross-build.sh
  scripts with SQLITE_DLLS=2.



TODO:

- improve documentation


2011-11-15
Christian Werner
mailto:chw@ch-werner.de
