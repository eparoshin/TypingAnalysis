TEMPLATE = app
TARGET = TypingAnalysis

QT       += core gui
CONFIG   += no_keywords

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 warn_on

DEFINES += KEYBOARD_HANDLER_DEBUG


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

win32 {
  win32-msvc*{
    QMAKE_CXXFLAGS_WARN_ON ~= s/-W./-W4
    QMAKE_CXXFLAGS += /MP /permissive-

    LIBS += -luser32
  }

  win32-g++*{
  }

  win32-clang*{
  }
}

linux {
  linux-g++*{
  }

  linux-clang*{
  }
}

macx {
  macx-g++*{
  }

 macx-clang*{
 }
}

# You must configure the kit as follows.
# Go to:
# Kit -> Build -> Build Steps
# Add Conan install as the first step

# 3d party library related code
#CONFIG += file_copies
#COPIES += SharedDllFiles
#SharedDllFiles.files = $$files($${OUT_PWD}/3dparty/dll/*.dll)
#CONFIG(release, debug|release): SharedDllFiles.path = $${OUT_PWD}/release
#else:CONFIG(debug, debug|release):SharedDllFiles.path = $${OUT_PWD}/debug

INCLUDEPATH += $${OUT_PWD}/3dparty/include

win32 {
  CONFIG(release, debug|release): LIBS += -L$${OUT_PWD}/3dparty/lib -ltbb
  else:CONFIG(debug, debug|release): LIBS += -L$${OUT_PWD}/3dparty/lib -ltbb_debug
}

# Qwt related includes and libraries
INCLUDEPATH += $${OUT_PWD}/3dparty/include/qwt

win32 {
  CONFIG(release, debug|release): LIBS += -L$${OUT_PWD}/3dparty/lib -lqwt
  else:CONFIG(debug, debug|release): LIBS += -L$${OUT_PWD}/3dparty/lib -lqwtd
}


HEADERS += \
  Compute/ParallelMode.h \
  Compute/ParallelModule.h \
  Compute/ParallelSerial.h \
  Compute/ParallelTbb.h \
  Interface/KeyboardShutter.h \
  Interface/Plotter.h \
  Interface/SeanceView.h \
  Interface/SeanceViewController.h \
  Interface/SessionFlusher.h \
  Interface/StatisticsView.h \
  Interface/TextModeController.h \
  Interface/TextModeView.h \
  Interface/TextPrinter.h \
  Kernel/AnalyticalModule.h \
  Kernel/FingerLayout.h \
  Kernel/KeyEvent.h \
  Kernel/KeyFlags.h \
  Kernel/MathFunction.h \
  Kernel/PlotData.h \
  Kernel/Seance.h \
  Kernel/SeanceMaker.h \
  Kernel/SeanceManager.h \
  Kernel/SeanceViewData.h \
  Kernel/Session.h \
  Kernel/SessionSelector.h \
  Kernel/SessionToTreeConverter.h \
  Kernel/TextData.h \
  Kernel/TextDataTree.h \
  Kernel/TextMode.h \
  Kernel/TextModule.h \
  Keyboard/AnyKeyboardKiller.h \
  Keyboard/KeyID.h \
  Keyboard/KeyPosition.h \
  Keyboard/KeyTextData.h \
  Keyboard/KeyboardHandler.h \
  Keyboard/KeyboardListener.h \
  Keyboard/ListenerExceptionHandler.h \
  Keyboard/RawKeyEvent.h \
  Library/AnyObject/AnyMovable.h \
  Library/Observer/Impl/Observable.h \
  Library/Observer/Impl/ObservableImpl.h \
  Library/Observer/Impl/Observer.h \
  Library/Observer/Impl/Source.h \
  Library/Observer/Impl/TypeHelper.h \
  Library/Observer/Observer.h \
  Library/Singleton/AnyGlobalAccess.h \
  Library/StlExtension/MvcWrappers.h \
  Library/StlExtension/Supressor.h \
  Library/StlExtension/ThreadDetachable.h \
  Library/StlExtension/VTree.h \
  Library/TypeList/ElementList.h \
  Library/TypeList/NullType.h \
  Library/TypeList/TypeList.h \
  Library/FunctionModuleBase.h \
  Library/Selector.h \
  Qt/AppState.h \
  Qt/AppStatus.h \
  Qt/MainWindow.h \
  Qt/SeanceDescriptionModel.h \
  Qt/QtLoopExceptionHandler.h \
  Application.h \
  ApplicationGUI.h \
  ApplicationGlobals.h \
  ApplicationImpl.h \
  ApplicationKernel.h \
  AppStatusAccess.h \
  ExceptionHandler.h \
  InstructionLevels.h \
  KeyboardHandlerAccess.h \
  ParallelModuleAccess.h \
  Qt/SessionStatisticsModel.h \
  QtLoopException.h \
  SimdDetector.h \
  SimdDetectorAccess.h \
  TimeApp.h \
  Timer.h \
  TimerAccess.h

SOURCES += \
  3dparty/vectorclass/instrset_detect.cpp \
  Compute/ParallelMode.cpp \
  Compute/ParallelModule.cpp \
  Compute/ParallelSerial.cpp \
  Compute/ParallelTbb.cpp \
  Interface/KeyboardShutter.cpp \
  Interface/Plotter.cpp \
  Interface/SeanceView.cpp \
  Interface/SeanceViewController.cpp \
  Interface/SessionFlusher.cpp \
  Interface/StatisticsView.cpp \
  Interface/TextModeController.cpp \
  Interface/TextModeView.cpp \
  Interface/TextPrinter.cpp \
  Kernel/AnalyticalModule.cpp \
  Kernel/FingerLayout.cpp \
  Kernel/KeyEvent.cpp \
  Kernel/KeyFlags.cpp \
  Kernel/MathFunction.cpp \
  Kernel/PlotData.cpp \
  Kernel/Seance.cpp \
  Kernel/SeanceMaker.cpp \
  Kernel/SeanceManager.cpp \
  Kernel/SeanceViewData.cpp \
  Kernel/Session.cpp \
  Kernel/SessionSelector.cpp \
  Kernel/SessionToTreeConverter.cpp \
  Kernel/TextData.cpp \
  Kernel/TextDataTree.cpp \
  Kernel/TextMode.cpp \
  Kernel/TextModule.cpp \
  Keyboard/KeyID.cpp \
  Keyboard/KeyTextData.cpp \
  Keyboard/KeyboardHandler.cpp \
  Keyboard/KeyboardListener.cpp \
  Keyboard/ListenerExceptionHandler.cpp \
  Keyboard/RawKeyEvent.cpp \
  Qt/AppState.cpp \
  Qt/AppStatus.cpp \
  Qt/MainWindow.cpp \
  Qt/QtLoopExceptionHandler.cpp \
  Qt/SeanceDescriptionModel.cpp \
  Application.cpp \
  ApplicationGUI.cpp \
  ApplicationGlobals.cpp \
  ApplicationImpl.cpp \
  ApplicationKernel.cpp \
  AppStatusAccess.cpp \
  ExceptionHandler.cpp \
  ParallelModuleAccess.cpp \
  Qt/SessionStatisticsModel.cpp \
  SimdDetector.cpp \
  SimdDetectorAccess.cpp \
  TimeApp.cpp \
  Timer.cpp \
  main.cpp

FORMS += \
  Qt/MainWindow.ui


win32 {
  win32-msvc*{
    HEADERS += \
      Compute/ParallelPpl.h

    SOURCES += \
      Compute/ParallelPpl.cpp
  }

    HEADERS += \
    Compute/ParallelWin.h \
    Keyboard/Windows/KeyboardListenerWin.h \
    Keyboard/Windows/MessageWindow.h \
    Keyboard/Windows/KeyIDWin.h \
    Keyboard/Windows/KeyMapper.h \
    Keyboard/Windows/KeyPositionWin.h \
    Keyboard/Windows/KeyShifters.h \
    Keyboard/Windows/KeyTextMaker.h \
    Keyboard/Windows/RawInputHook.h \
    Keyboard/Windows/RawInputReader.h \
    Keyboard/Windows/VkCode.h \
    Keyboard/Windows/WinKeyboardApi.h


    SOURCES += \
    Compute/ParallelWin.cpp \
    Keyboard/Windows/KeyboardListenerWin.cpp \
    Keyboard/Windows/KeyIDWin.cpp \
    Keyboard/Windows/KeyMapper.cpp \
    Keyboard/Windows/KeyPositionWin.cpp \
    Keyboard/Windows/KeyShifters.cpp \
    Keyboard/Windows/KeyTextMaker.cpp \
    Keyboard/Windows/RawInputReader.cpp \
    Keyboard/Windows/VkCode.cpp \
    Keyboard/Windows/WinKeyboardApi.cpp
}

macx {
    HEADERS += \
    Compute/ParallelMac.h \
    Keyboard/Macos/KeyboardListenerMac.h

    SOURCES += \
    Compute/ParallelMac.cpp \
    Keyboard/Macos/KeyboardListenerMac.cpp
}

linux {
    HEADERS += \
    Compute/ParallelLin.h \
    Keyboard/Linux/KeyboardListenerLin.h

    SOURCES += \
    Compute/ParallelLin.cpp \
    Keyboard/Linux/KeyboardListenerLin.cpp
}

contains(DEFINES, KEYBOARD_HANDLER_DEBUG) {
    HEADERS += \
    AppDebug/KeyboardHandlerDebugGUI.h \
    AppDebug/KeyboardHandlerDebugOut.h
    SOURCES += \
    AppDebug/KeyboardHandlerDebugGUI.cpp \
    AppDebug/KeyboardHandlerDebugOut.cpp
}

# The custom compiler compiles on AVX level
win32 {
  win32-msvc*{
    QMAKE_CXXFLAGS += -EHsc
    AVX_FLAGS = /arch:AVX
    AVX_OUT = /Fo${QMAKE_FILE_OUT}
  }

  win32-g++*{
    AVX_FLAGS = -mavx
    AVX_OUT = -o${QMAKE_FILE_OUT}
  }

  win32-clang*{
  }

  SOURCES_AVX += Kernel/MathFunctionAVX.cpp
  avx_compiler.name = avx_compiler
  avx_compiler.input = SOURCES_AVX
  avx_compiler.dependency_type = TYPE_C
  avx_compiler.variable_out = OBJECTS
  avx_compiler.output = \
    ${QMAKE_VAR_OBJECTS_DIR}${QMAKE_FILE_IN_BASE}$${first(QMAKE_EXT_OBJ)}
  avx_compiler.commands = $${QMAKE_CXX} $(CXXFLAGS) $${AVX_FLAGS} \
    $(INCPATH) -c ${QMAKE_FILE_IN} $${AVX_OUT}
  QMAKE_EXTRA_COMPILERS += avx_compiler
}

linux {
  linux-g++*{
  }

  linux-clang*{
  }
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
