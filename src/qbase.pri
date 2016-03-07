isEmpty(TARGET):error("You must set TARGET before include()'ing $${_FILE_}")
INCLUDEPATH *= $$QMAKE_INCDIR_QT/$$TARGET #just for today to have some compat
!isEmpty(RCC_DIR): INCLUDEPATH += $$RCC_DIR
isEmpty(QT_ARCH):!isEmpty(ARCH):QT_ARCH=$$ARCH #another compat that will rot for change #215700
TEMPLATE	= lib
isEmpty(QT_MAJOR_VERSION) {
   VERSION=4.7.4
} else {
   VERSION=$${QT_MAJOR_VERSION}.$${QT_MINOR_VERSION}.$${QT_PATCH_VERSION}
}
mac:!contains(QMAKE_EXT_C, .mm):QMAKE_EXT_C += .mm

#load up the headers info
CONFIG += qt_install_headers
HEADERS_PRI = $$QT_BUILD_TREE/include/$$TARGET/headers.pri
include($$HEADERS_PRI, "", true)|clear(HEADERS_PRI)

#version overriding
win32 {
    #because libnetwork.pro could be qmake'd (qmade?) before libqcore.pro we
    #need to override the version of libq* in all other libq*'s just to be
    #sure the same version is used
	VERSIONS_LIST = $$split(VERSION, ".")
    QT_LIBS_OVERRIDE = $$member(VERSIONS_LIST, 0)
	for(lib, $$list(qtcore qtgui qtnetwork qtxml qtopengl qtsql qt3support)) {
        eval(QMAKE_$${upper($$lib)}_VERSION_OVERRIDE = $$QT_LIBS_OVERRIDE)
	eval(QMAKE_$${upper($$lib)}D_VERSION_OVERRIDE = $$QT_LIBS_OVERRIDE)
    }
}

#other
DESTDIR		 = $$QMAKE_LIBDIR_QT
win32:!wince*:DLLDESTDIR = $$[QT_INSTALL_PREFIX]/bin

CONFIG		+= qt warn_on depend_includepath
CONFIG          += qmake_cache target_qt 
CONFIG          -= fix_output_dirs
win32|mac:!macx-xcode:CONFIG += debug_and_release
linux*:QMAKE_LFLAGS += $$QMAKE_LFLAGS_NOUNDEF

contains(QT_CONFIG, reduce_exports):CONFIG += hide_symbols
unix:contains(QT_CONFIG, reduce_relocations):CONFIG += bsymbolic_functions
contains(QT_CONFIG, largefile):CONFIG += largefile

#mac frameworks
mac:!static:contains(QT_CONFIG, qt_framework) {
   #QMAKE_FRAMEWORK_VERSION = 4.0
   CONFIG += lib_bundle qt_no_framework_direct_includes qt_framework
   CONFIG(debug, debug|release) {
      !build_pass:CONFIG += build_all
   } else { #release
      !debug_and_release|build_pass {
	  CONFIG -= qt_install_headers #no need to install these as well
	  FRAMEWORK_HEADERS.version = Versions
	  FRAMEWORK_HEADERS.files = $$SYNCQT.HEADER_FILES $$SYNCQT.HEADER_CLASSES
      	  FRAMEWORK_HEADERS.path = Headers
      	  equals(TARGET, QtCore) {
              #headers generated by configure
              !contains(FRAMEWORK_HEADERS.files, .*/qconfig.h) {
	          FRAMEWORK_HEADERS.files *= $$QT_BUILD_TREE/src/corelib/global/qconfig.h 
	      }
          }
      }
      QMAKE_BUNDLE_DATA += FRAMEWORK_HEADERS
   }
}

mac {
   CONFIG += explicitlib
   macx-g++ {
       QMAKE_CFLAGS += -fconstant-cfstrings
       QMAKE_CXXFLAGS += -fconstant-cfstrings
   }
}

win32:!shared:CONFIG += static

win32-borland {
    mng:QMAKE_CFLAGS_WARN_ON	+= -w-par
    mng:QMAKE_CXXFLAGS_WARN_ON	+= -w-par
    # Keep the size of the .tds file for the Qt library smaller than
    # 34 Mbytes to avoid linking problems
    QMAKE_CFLAGS_DEBUG += -vi -y-
    QMAKE_CXXFLAGS_DEBUG += -vi -y-
}

win32 {
    INCLUDEPATH += tmp
    !static: DEFINES+=QT_MAKEDLL
}
symbian {
    shared {
        DEFINES+=QT_MAKEDLL
        TARGET.CAPABILITY = All -Tcb

        # When building without autotests, DEF files are used by default.
        # This is to maintain binary compatibility with previous releases.
        # To explicitly disable DEF files usage, eg. when lots of code churn is
        # going on, and functions may be added and removed before shipping, 
        # configure with -no-usedeffiles
        # WARNING - disabling DEF files *will* break BC with previous released versions 
        # of Qt, and the only compatibility will be between this build of Qt and anything 
        # built in this exact environment.  *Never* use this when building a version 
        # for release.
        contains(CONFIG, def_files) {
            DEF_FILE=../s60installs
        }
    }
    load(armcc_warnings)

    # workaround for the fact that some of our required includes in Symbian^3
    # now depend upon files in epoc32/include/platform
    INCLUDEPATH += $$OS_LAYER_SYSTEMINCLUDE
}
win32-borland:INCLUDEPATH += kernel

aix-g++* {
     QMAKE_CFLAGS   += -mminimal-toc
     QMAKE_CXXFLAGS += -mminimal-toc
}

embedded {
     EMBEDDED_H = $$EMBEDDED_CPP
}

DEPENDPATH += ;$$NETWORK_H;$$KERNEL_H;$$WIDGETS_H;$$SQL_H;$$TABLE_H;$$DIALOGS_H;
DEPENDPATH += $$ICONVIEW_H;$$OPENGL_H;$$THREAD_H;$$TOOLS_H;$$CODECS_H;
DEPENDPATH += $$WORKSPACE_H;$$XML_H;$$STYLES_H;$$COMPAT_H
embedded:DEPENDPATH += ;$$EMBEDDED_H

!static:PRL_EXPORT_DEFINES += QT_SHARED

#install directives
include(qt_install.pri)

unix:!symbian {
   CONFIG     += create_libtool create_pc explicitlib
   QMAKE_LIBTOOL_LIBDIR = $$[QT_INSTALL_LIBS]
   QMAKE_PRL_LIBDIR = $$[QT_INSTALL_LIBS]
   QMAKE_PKGCONFIG_LIBDIR = $$[QT_INSTALL_LIBS]
   QMAKE_PKGCONFIG_INCDIR = $$[QT_INSTALL_HEADERS]/$$TARGET
   QMAKE_PKGCONFIG_CFLAGS = -I$$[QT_INSTALL_HEADERS]
   QMAKE_PKGCONFIG_DESTDIR = pkgconfig
   include_replace.match = $$QMAKE_INCDIR_QT
   include_replace.replace = $$[QT_INSTALL_HEADERS]
   lib_replace.match = $$QMAKE_LIBDIR_QT
   lib_replace.replace = $$[QT_INSTALL_LIBS]
   prefix_replace.match = $$QT_BUILD_TREE
   prefix_replace.replace = $$[QT_INSTALL_PREFIX]
   QMAKE_PRL_INSTALL_REPLACE += include_replace lib_replace
   QMAKE_LIBTOOL_INSTALL_REPLACE += include_replace lib_replace
   QMAKE_PKGCONFIG_INSTALL_REPLACE += include_replace lib_replace prefix_replace
}

contains(QT_PRODUCT, OpenSource.*):DEFINES *= QT_OPENSOURCE
DEFINES *= QT_NO_CAST_TO_ASCII QT_ASCII_CAST_WARNINGS
contains(QT_CONFIG, qt3support):DEFINES *= QT3_SUPPORT
DEFINES *= QT_MOC_COMPAT #we don't need warnings from calling moc code in our generated code
DEFINES *= QT_USE_FAST_OPERATOR_PLUS QT_USE_FAST_CONCATENATION

TARGET = $$qtLibraryTarget($$TARGET$$QT_LIBINFIX) #do this towards the end

qtPrepareTool(QMAKE_LUPDATE, lupdate)
qtPrepareTool(QMAKE_LRELEASE, lrelease)

moc_dir.name = moc_location
moc_dir.variable = QMAKE_MOC

uic_dir.name = uic_location
uic_dir.variable = QMAKE_UIC

rcc_dir.name = rcc_location
rcc_dir.variable = QMAKE_RCC

lupdate_dir.name = lupdate_location
lupdate_dir.variable = QMAKE_LUPDATE

lrelease_dir.name = lrelease_location
lrelease_dir.variable = QMAKE_LRELEASE

QMAKE_PKGCONFIG_VARIABLES += moc_dir uic_dir rcc_dir lupdate_dir lrelease_dir

include(qt_targets.pri)

win32:DEFINES+=_USE_MATH_DEFINES

symbian {
    # Make partial upgrade SIS file for all dll's except webkit and s60main
    !contains(TARGET.UID3, 0x200267C2):!contains(TARGET.UID3, 0xE00267C2):!contains(TARGET.UID3, 0x2001E61F):!contains(TARGET.UID3, 0xE001E61F) {
        # Partial upgrade SIS file
        vendorinfo = \
            "; Localised Vendor name" \
            "%{\"Nokia\"}" \
            " " \
            "; Unique Vendor name" \
            ":\"Nokia, Qt\"" \
            " "
        isEmpty(QT_LIBINFIX): PARTIAL_UPGRADE_UID = 0x2001E61C
        else: PARTIAL_UPGRADE_UID = 0xE001E61C

        pu_header = "; Partial upgrade package for testing $${TARGET} changes without reinstalling everything" \
                    "$${LITERAL_HASH}{\"$${TARGET}\"}, ($$PARTIAL_UPGRADE_UID), $${QT_MAJOR_VERSION},$${QT_MINOR_VERSION},$${QT_PATCH_VERSION}, TYPE=PU"
        partial_upgrade.pkg_prerules = pu_header vendorinfo
        partial_upgrade.sources = $$QMAKE_LIBDIR_QT/$${TARGET}.dll
        partial_upgrade.path = c:/sys/bin
        DEPLOYMENT += partial_upgrade
    }
}
