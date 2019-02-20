#include "scenes/settings_scene.h"

settingsScene::settingsScene(QObject* parent) :
    QGraphicsScene(parent)
{
    //addItem(&userSet);

    setupNumPad();

    setBackgroundBrush(Qt::black);

    timeLabel.setFrameStyle(QFrame::NoFrame | QFrame::Plain);
    timeLabel.setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    timeLabel.setFixedSize(120, 50);
    timeLabel.setGeometry(10,65,120,50);
    timeLabel.setStyleSheet("QLabel { background-color : black; color : white; }");
    addWidget(&timeLabel);

    dateLabel.setFrameStyle(QFrame::Panel | QFrame::Sunken);
    dateLabel.setFixedSize(120, 50);
    dateLabel.setGeometry(10,10,120,50);
    dateLabel.setStyleSheet("QLabel { background-color : black; color : white; }");
    dateLabel.setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    addWidget(&dateLabel);

    connect(&userSet, SIGNAL(zeroCurrent()), this, SLOT(onZeroCurrent()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(showDateTime()));
    timer.start(1000);

    setTime.setText("Change Time");
    setTime.setFixedSize(130,50);
    setTime.setGeometry(130,65,120,50);
    addWidget(&setTime);

    setDate.setText("Change Date");
    setDate.setFixedSize(130,50);
    setDate.setGeometry(130,10,120,50);
    addWidget(&setDate);

    connect(&keyEnt, SIGNAL(clicked(bool)), this, SLOT(onFinishChange()));
    connect(&setTime, SIGNAL(clicked(bool)), this, SLOT(onChangeTime()));
    connect(&setDate, SIGNAL(clicked(bool)), this, SLOT(onChangeDate()));

    connect(&key1, SIGNAL(clicked(bool)), this, SLOT(on1Pressed()));
    connect(&key2, SIGNAL(clicked(bool)), this, SLOT(on2Pressed()));
    connect(&key3, SIGNAL(clicked(bool)), this, SLOT(on3Pressed()));
    connect(&key4, SIGNAL(clicked(bool)), this, SLOT(on4Pressed()));
    connect(&key5, SIGNAL(clicked(bool)), this, SLOT(on5Pressed()));
    connect(&key6, SIGNAL(clicked(bool)), this, SLOT(on6Pressed()));
    connect(&key7, SIGNAL(clicked(bool)), this, SLOT(on7Pressed()));
    connect(&key8, SIGNAL(clicked(bool)), this, SLOT(on8Pressed()));
    connect(&key9, SIGNAL(clicked(bool)), this, SLOT(on9Pressed()));
    connect(&key0, SIGNAL(clicked(bool)), this, SLOT(on0Pressed()));

    connect(&keyClr, SIGNAL(clicked(bool)), this, SLOT(onClrPressed()));

//    cmdLog.setFixedSize(300,350);
//    cmdLog.setGeometry(10,40,300,350);
//    addWidget(&cmdLog);
}

QRectF settingsScene::boundingRect() const
{
    return QRectF(0,0,800,480);
}

void settingsScene::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //Set Clipping Rect
    painter->setClipRect(boundingRect());

    if(isActive()) {
        update();
    }

}

void settingsScene::showDateTime() {
    time = QTime::currentTime();

    if (editType == 0) {
        timeText = time.toString("hh:mm:ss");
        dateText = QDate::currentDate().toString("MM/dd/yyyy");
    } else if(editType == 1) {
        timeText = time.toString("hh:mm:ss");
    } else if (editType == 2) {
        dateText = QDate::currentDate().toString("MM/dd/yyyy");
    }

    dateLabel.setText(dateText);
    timeLabel.setText(timeText);
}

void settingsScene::setupNumPad() {

    key1.setText("1");
    key2.setText("2");
    key3.setText("3");
    key4.setText("4");
    key5.setText("5");
    key6.setText("6");
    key7.setText("7");
    key8.setText("8");
    key9.setText("9");
    keyClr.setText("Clr");
    key0.setText("0");
    keyEnt.setText("Ent");

    int hwSize = 65;
    int hwSize2 = hwSize + hwSize;
    int hwSize3 = hwSize2 + hwSize;
    int initX = 275;
    int initY = 10;

    key1.setFixedSize(hwSize,hwSize);
    key2.setFixedSize(hwSize,hwSize);
    key3.setFixedSize(hwSize,hwSize);
    key4.setFixedSize(hwSize,hwSize);
    key5.setFixedSize(hwSize,hwSize);
    key6.setFixedSize(hwSize,hwSize);
    key7.setFixedSize(hwSize,hwSize);
    key8.setFixedSize(hwSize,hwSize);
    key9.setFixedSize(hwSize,hwSize);
    keyClr.setFixedSize(hwSize,hwSize);
    key0.setFixedSize(hwSize,hwSize);
    keyEnt.setFixedSize(hwSize,hwSize);

    key1.setGeometry(initX, initY, hwSize, hwSize);
    key2.setGeometry(initX+hwSize, initY, hwSize, hwSize);
    key3.setGeometry(initX+hwSize2, initY, hwSize, hwSize);

    key4.setGeometry(initX, initY+hwSize, hwSize, hwSize);
    key5.setGeometry(initX+hwSize, initY+hwSize, hwSize, hwSize);
    key6.setGeometry(initX+hwSize2, initY+hwSize, hwSize, hwSize);

    key7.setGeometry(initX, initY+hwSize2, hwSize, hwSize);
    key8.setGeometry(initX+hwSize, initY+hwSize2, hwSize, hwSize);
    key9.setGeometry(initX+hwSize2, initY+hwSize2, hwSize, hwSize);

    keyClr.setGeometry(initX, initY+hwSize3, hwSize, hwSize);
    key0.setGeometry(initX+hwSize, initY+hwSize3, hwSize, hwSize);
    keyEnt.setGeometry(initX+hwSize2, initY+hwSize3, hwSize, hwSize);

    key1.setVisible(false);
    key2.setVisible(false);
    key3.setVisible(false);
    key4.setVisible(false);
    key5.setVisible(false);
    key6.setVisible(false);
    key7.setVisible(false);
    key8.setVisible(false);
    key9.setVisible(false);
    keyClr.setVisible(false);
    key0.setVisible(false);
    keyEnt.setVisible(false);

    addWidget(&key1);
    addWidget(&key2);
    addWidget(&key3);
    addWidget(&key4);
    addWidget(&key5);
    addWidget(&key6);
    addWidget(&key7);
    addWidget(&key8);
    addWidget(&key9);
    addWidget(&keyClr);
    addWidget(&key0);
    addWidget(&keyEnt);

}

void settingsScene::onChangeTime() {
    key1.setVisible(true);
    key2.setVisible(true);
    key3.setVisible(true);
    key4.setVisible(true);
    key5.setVisible(true);
    key6.setVisible(true);
    key7.setVisible(true);
    key8.setVisible(true);
    key9.setVisible(true);
    keyClr.setVisible(true);
    key0.setVisible(true);
    keyEnt.setVisible(true);

    editType = 2;
    timeText.clear();
}

void settingsScene::onChangeDate() {
    key1.setVisible(true);
    key2.setVisible(true);
    key3.setVisible(true);
    key4.setVisible(true);
    key5.setVisible(true);
    key6.setVisible(true);
    key7.setVisible(true);
    key8.setVisible(true);
    key9.setVisible(true);
    keyClr.setVisible(true);
    key0.setVisible(true);
    keyEnt.setVisible(true);

    editType = 1;
    dateText.clear();
}

void settingsScene::onFinishChange() {
    key1.setVisible(false);
    key2.setVisible(false);
    key3.setVisible(false);
    key4.setVisible(false);
    key5.setVisible(false);
    key6.setVisible(false);
    key7.setVisible(false);
    key8.setVisible(false);
    key9.setVisible(false);
    keyClr.setVisible(false);
    key0.setVisible(false);
    keyEnt.setVisible(false);

    if (editType==1) {
        QDate dateToSet = QDate::fromString(dateLabel.text(), "MM/dd/yyyy");
        //qDebug() << "Attempting to change date to " + dateLabel.text();
        execCommand = "date +%Y%m%d -s " + dateToSet.toString("yyyyMMdd") ;
        qDebug() << "Command to execute '" + execCommand + "'";
    } else {
        //qDebug() << "Attempting to change time to " + timeText;
        execCommand = "date +%T -s " + timeLabel.text();
        qDebug() << "Command to execute '" + execCommand + "'";
    }

    hwClock.start(execCommand);
    hwClock.waitForFinished(-1); // will wait forever until finished

    QString stdout = hwClock.readAllStandardOutput();
    QString stderr = hwClock.readAllStandardError();
    qDebug() << stdout;
    qDebug() << stderr;

    execCommand = "hwclock -w";

    hwClock.start(execCommand);
    hwClock.waitForFinished(-1); // will wait forever until finished

    stdout = hwClock.readAllStandardOutput();
    stderr = hwClock.readAllStandardError();
    qDebug() << stdout;
    qDebug() << stderr;

    editType = 0;
}

void settingsScene::addSlashesOrColons() {
    if (editType == 1) {
        int dateLength = dateText.length();

        if (dateLength==2 || dateLength == 5) {
            dateText.append("/");
        } else if (dateLength == 10) {
            dateText.clear();
        }
    } else if (editType == 2) {
        int timeLength = timeText.length();

        if (timeLength==2 || timeLength == 5) {
            timeText.append(":");
        } else if (timeLength == 8) {
            timeText.clear();
        }
    }

}

void settingsScene::on1Pressed() {
    addSlashesOrColons();

    if (editType == 1) {
        dateText.append("1");
    } else {
        timeText.append("1");
    }

}

void settingsScene::on2Pressed() {
    addSlashesOrColons();

    if (editType == 1) {
        dateText.append("2");
    } else {
        timeText.append("2");
    }
}

void settingsScene::on3Pressed() {
    addSlashesOrColons();

    if (editType == 1) {
        dateText.append("3");
    } else {
        timeText.append("3");
    }
}

void settingsScene::on4Pressed() {
    addSlashesOrColons();
    if (editType == 1) {
        dateText.append("4");
    } else {
        timeText.append("4");
    }
}

void settingsScene::on5Pressed() {
    addSlashesOrColons();

    if (editType == 1) {
        dateText.append("5");
    } else {
        timeText.append("5");
    }
}

void settingsScene::on6Pressed() {
    addSlashesOrColons();

    if (editType == 1) {
        dateText.append("6");
    } else {
        timeText.append("6");
    }
}

void settingsScene::on7Pressed() {
    addSlashesOrColons();

    if (editType == 1) {
        dateText.append("7");
    } else {
        timeText.append("7");
    }
}

void settingsScene::on8Pressed() {
    addSlashesOrColons();

    if (editType == 1) {
        dateText.append("8");
    } else {
        timeText.append("8");
    }
}

void settingsScene::on9Pressed() {
    addSlashesOrColons();

    if (editType == 1) {
        dateText.append("9");
    } else {
        timeText.append("9");
    }
}

void settingsScene::on0Pressed() {
    addSlashesOrColons();

    if (editType == 1) {
        dateText.append("0");
    } else {
        timeText.append("0");
    }
}

void settingsScene::onClrPressed() {
    if (editType == 1) {
        dateText.clear();
    } else {
        timeText.clear();
    }
}
