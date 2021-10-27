#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
class QCloseEvent;
QT_END_NAMESPACE

namespace NSApplication {
namespace NSQt {

class CMainWindow : public QMainWindow {
  Q_OBJECT
public:
  CMainWindow(QWidget* parent = nullptr);
  ~CMainWindow();

  void closeEvent(QCloseEvent* event);

signals:
  bool closeMainWindow();

private:
  void adjustStaticInterface();
  void adjustSplitters();
  void adjustSplitter();
  void adjustSplitter2();
  void adjustSplitter3();
  void adjustSplitter5();
  void adjustSplitter6();
  void adjustButtonGroups();
  void adjustButtonGroup();
  void adjustButtonGroup2();
  void adjustButtonGroup3();

  std::unique_ptr<Ui::MainWindow> ui_;
};
} // namespace NSQt
} // namespace NSApplication

#endif // MAINWINDOW_H
