#include "mainwindow.h"
#include "./design/ui_mainwindow.h"
#include<QDebug>
#include <QLoggingCategory>

template<typename ...T>
void initTable(QTableWidget *table, T... args);
void setItem(QTableWidget *table, int x, int y, const QString& text);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QLoggingCategory::defaultCategory()->setEnabled(QtDebugMsg, true);
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    initTable(ui->genshin_boss_material, 132, 108, 30, 30, 30);
}

MainWindow::~MainWindow()
{
    delete ui;
}

template<typename ...T>
void initTable(QTableWidget *table, T... args)
{
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    table->setRowCount(1);
    const std::initializer_list<int> list{args...};
    int index = 0;
    for (const int width : list)
    {
        table->setColumnWidth(index++, width);
    }



    setItem(table, 0, 0, "机械发条备件-格菲利亚");
    setItem(table, 0, 1, "冰封组曲-格菲利亚");
    setItem(table, 0, 2, "999");
    setItem(table, 0, 3, "999");
    setItem(table, 0, 4, "999");
}

void setItem(QTableWidget *table, const int x, const int y, const QString& text)
{
    auto *widget = new QTableWidgetItem(text);
    widget->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    table->setItem(x, y, widget);
}