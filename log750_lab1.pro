# The simplest application example: 20 lines of code and yet all the power !

# A Viewer class is derived from QGLViewer and its <code>draw()</code> function is overloaded to
# specify the user defined OpenGL orders that describe the scene.

# This is the first example you should try, as it explains some of the default keyboard shortcuts
# and the mouse behavior of the viewer.

# This example can be cut and pasted to start the development of a new application.

TEMPLATE = app
TARGET   = simpleViewer

QMAKE_CXXFLAGS_WARN_ON += -Wno-unknown-pragmas

# Add your .ui file here
FORMS += untitled.ui

HEADERS  = simpleViewer.h \
    scenecontroller.h \
    scenenode.h \
    scenetransformation.h \
    scene.h \
    sceneshape.h \
    scenetranslation.h \
    scenesphere.h \
    scenerotation.h \
    scenescaling.h \
    scenedisk.h
SOURCES  = main.cpp \
    simpleViewer.cpp\
    scenecontroller.cpp \
    scenenode.cpp \
    scenetransformation.cpp \
    scene.cpp \
    sceneshape.cpp \
    scenetranslation.cpp \
    scenesphere.cpp \
    scenerotation.cpp \
    scenescaling.cpp \
    scenedisk.cpp

QT *= xml opengl
QT += widgets

#****Ajouter ceci si SimpleViewer.exe*****
CONFIG += opengl console
QT += opengl
LIBS += -lglut32
#*****************************************

# Might have to edit this to reflect the platform dependant name.
win32: LIBS += -lglut32
macx: LIBS += -framework GLUT

#CONFIG -= debug debug_and_release
CONFIG += debug_and_release qt opengl warn_on thread rtti console embed_manifest_exe

# --------------------------------------------------------------------------------------

# The remaining of this configuration tries to automatically detect the library paths.
# In your applications, you can probably simply use (see doc/compilation.html for details) :

#INCLUDEPATH *= C:/Qt/libQGLViewer-2.4.0
#LIBS *= -LC:Qt/libQGLViewer-2.4.0/QGLViewer -lQGLViewer2

# Change these paths according to your configuration.

# --------------------------------------------------------------------------------------

win32 {
  LIB_FILE = QGLViewer
  CONFIG(debug, debug|release) {
    LIB_FILE = $$join(LIB_FILE,,,d)
  }
  LIB_FILE = $$join(LIB_FILE,,,2)
  LIBS += -l$${LIB_FILE}
}
macx {
  LIBS += -framework QGLViewer
}
