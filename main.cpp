#include <QApplication>
#include <QSlider>
#include <QVBoxLayout>
#include <QPainter>
#include <QPaintEvent>
#include <iostream>

class ImageCircle : public QWidget{
private:
    QPixmap greenCircle;
    QPixmap yellowCircle;
    QPixmap redCircle;
    QPixmap currentCircle;
public:
    explicit ImageCircle(QWidget *parent) {
        setParent(parent);
        greenCircle = QPixmap("D:\\SkillboxProjects\\qt2\\ex1\\pictures\\green.png");
        yellowCircle = QPixmap("D:\\SkillboxProjects\\qt2\\ex1\\pictures\\yellow.png");
        redCircle = QPixmap("D:\\SkillboxProjects\\qt2\\ex1\\pictures\\red.png");
        currentCircle = greenCircle;
    }
    void paintEvent(QPaintEvent *e) override {
        QPainter p(this);
        p.drawPixmap(e->rect(), currentCircle);
    }
    void setGreen() {
        currentCircle = greenCircle;
        update();
    }
    void setYellow() {
        currentCircle = yellowCircle;
        update();
    }
    void setRed() {
        currentCircle = redCircle;
        update();
    }
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto window = new QWidget;
    window->setFixedSize(550,500);
    auto slider = new QSlider(Qt::Horizontal);
    slider->move(1000,500);
    slider->setMinimum(0);
    slider->setMaximum(99);
    auto circle = new ImageCircle(nullptr);
    auto layout = new QVBoxLayout(window);
    layout->addWidget(slider);
    layout->addWidget(circle);
    QObject::connect(slider, &QSlider::valueChanged, [slider, circle]()
    {
        if(slider->value() >= 0 && slider->value() <= 33) {
            circle->setGreen();
        } else if (slider->value() >= 34 && slider->value() <= 66){
            circle->setYellow();
        } else {
            circle->setRed();
        }
    });
    window->show();
    return QApplication::exec();
}
