#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

///
/// \brief MainWindow::MainWindow - po prostu konstruktor
/// \param parent - wskaźnik na "okno-rodzica"
///
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMessageBox::information(this, "Informacja",
                             "Ten program reaguje na <br/>"
                             "<b><span style=\"color:red\">kliknięcia myszą</span></b> <br/>"
                             "w obszarze roboczym <i>okna programu</i>");
}

MainWindow::~MainWindow()
{
    delete ui;
}

///
/// \brief MainWindow::on_action_Zakoncz_triggered - kończy działanie aplikacji
///
void MainWindow::on_action_Zakoncz_triggered()
{
    qApp->quit(); // qApp jest specjalnym makrem, ale o tym później
}

///
/// \brief MainWindow::on_action_O_programie_triggered - obsługuje kliknięcie ("triggering") pozycji menu pt. "O programie"
/// Struktura menu jest zdefiniowane w pliku `mainwindow.ui`.
///
void MainWindow::on_action_O_programie_triggered()
{
    QMessageBox::information(this, "O programie", "W tym prostym programie można klikać, a może i coś więcej");
}
