/* zncconfig.h.  Generated from zncconfig.h.in by configure.  */
/* zncconfig.h.in.  Generated from configure.ac by autoheader.  */

#ifndef ZNCCONFIG_H
#define ZNCCONFIG_H

/* Use poll() instead of select() */
/* #undef CSOCK_USE_POLL */

/* Define if c-ares is enabled */
/* #undef HAVE_C_ARES */

/* Define to 1 if you have the `getopt_long' function. */
#define HAVE_GETOPT_LONG 1

/* Define to 1 if you have the `getphassphrase' function. */
/* #undef HAVE_GETPHASSPHRASE */

/* Define if IPv6 support is enabled */
#define HAVE_IPV6 1

/* Define to 1 if you have the `crypto' library (-lcrypto). */
/* #undef HAVE_LIBCRYPTO */

/* Define to 1 if you have the `gnugetopt' library (-lgnugetopt). */
/* #undef HAVE_LIBGNUGETOPT */

/* Define if openssl is enabled */
#define HAVE_LIBSSL 1

/* Define to 1 if you have the `lstat' function. */
#define HAVE_LSTAT 1

/* Define to 1 or 0, depending whether the compiler supports simple visibility
   declarations. */
#define HAVE_VISIBILITY 1

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "znc"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "znc 0.202"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "znc"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "0.202"

/* Define if ZNC should be runnable without installation */
#define RUN_FROM_SOURCE 1

/* Define for debugging */
/* #undef _DEBUG */

/* Number of bits in a file offset, on hosts where this is settable. */
/* #undef _FILE_OFFSET_BITS */

/* Enable extra debugging checks in libstdc++ */
/* #undef _GLIBCXX_CONCEPT_CHECKS */

/* Enable extra debugging checks in libstdc++ */
/* #undef _GLIBCXX_DEBUG */

/* Enable extra debugging checks in libstdc++ */
/* #undef _GLIBCXX_DEBUG_PEDANTIC */

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */

#endif /* ZNCCONFIG_H */
