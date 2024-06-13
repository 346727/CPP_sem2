#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action_Koniec, SIGNAL(triggered()), this, SLOT(koniec_programu()) );
    //connect(ui->przycisk, SIGNAL(clicked()), ui->widget, SLOT(toggle_animation()));

    connect(ui->przycisk, &QPushButton::clicked, this, &MainWindow::togglePlayPause);

    updateButtonIcon();

    QPalette pal = QPalette();

    // set black background
    // Qt::black / "#000000" / "black"
    pal.setColor(QPalette::Window, Qt::lightGray);

    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->show();
}

MainWindow::~MainWindow()
{


    delete ui;
}

void MainWindow::updateButtonIcon()
{
    QIcon icon(isPlaying ? ":/img/media-playback-pause.png" : ":/img/media-playback-start.png");
    if (icon.isNull()) {
        qWarning() << "Icon not found!";
    } else {
        ui->przycisk->setIcon(icon);
    }
}

void MainWindow::togglePlayPause()
{
    isPlaying = !isPlaying;
    updateButtonIcon();
}

void MainWindow::koniec_programu()
{

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Koniec programu", "Czy na pewno chcesz zakończyć program?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        qApp->quit();
    }
}


void MainWindow::on_action_O_programie_triggered()
{
 QMessageBox::aboutQt(this,"O wspaniałym programie");
}
