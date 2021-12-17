/********************************************************************************
** Form generated from reading UI file 'edititemdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITITEMDIALOG_H
#define UI_EDITITEMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditItemDialog
{
public:
    QWidget *layoutWidget;
    QFormLayout *formLayout_3;
    QFormLayout *formLayout;
    QLineEdit *itemName;
    QLabel *name;
    QSpinBox *unitCost;
    QLabel *cost;
    QDoubleSpinBox *stockLevel;
    QLabel *level;
    QCheckBox *reorder;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *formLayout_2;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *EditItemDialog)
    {
        if (EditItemDialog->objectName().isEmpty())
            EditItemDialog->setObjectName(QString::fromUtf8("EditItemDialog"));
        EditItemDialog->resize(343, 191);
        layoutWidget = new QWidget(EditItemDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 300, 136));
        formLayout_3 = new QFormLayout(layoutWidget);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        itemName = new QLineEdit(layoutWidget);
        itemName->setObjectName(QString::fromUtf8("itemName"));

        formLayout->setWidget(0, QFormLayout::LabelRole, itemName);

        name = new QLabel(layoutWidget);
        name->setObjectName(QString::fromUtf8("name"));

        formLayout->setWidget(0, QFormLayout::FieldRole, name);

        unitCost = new QSpinBox(layoutWidget);
        unitCost->setObjectName(QString::fromUtf8("unitCost"));

        formLayout->setWidget(1, QFormLayout::LabelRole, unitCost);

        cost = new QLabel(layoutWidget);
        cost->setObjectName(QString::fromUtf8("cost"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cost);

        stockLevel = new QDoubleSpinBox(layoutWidget);
        stockLevel->setObjectName(QString::fromUtf8("stockLevel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, stockLevel);

        level = new QLabel(layoutWidget);
        level->setObjectName(QString::fromUtf8("level"));

        formLayout->setWidget(2, QFormLayout::FieldRole, level);

        reorder = new QCheckBox(layoutWidget);
        reorder->setObjectName(QString::fromUtf8("reorder"));

        formLayout->setWidget(3, QFormLayout::LabelRole, reorder);


        formLayout_3->setLayout(0, QFormLayout::LabelRole, formLayout);

        horizontalSpacer_2 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout_3->setItem(0, QFormLayout::FieldRole, horizontalSpacer_2);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, buttonBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout_2->setItem(0, QFormLayout::FieldRole, horizontalSpacer);


        formLayout_3->setLayout(1, QFormLayout::LabelRole, formLayout_2);


        retranslateUi(EditItemDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EditItemDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EditItemDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EditItemDialog);
    } // setupUi

    void retranslateUi(QDialog *EditItemDialog)
    {
        EditItemDialog->setWindowTitle(QCoreApplication::translate("EditItemDialog", "Dialog", nullptr));
        name->setText(QCoreApplication::translate("EditItemDialog", "Item Name", nullptr));
        cost->setText(QCoreApplication::translate("EditItemDialog", "Item Cost", nullptr));
        level->setText(QCoreApplication::translate("EditItemDialog", "Stock Level", nullptr));
        reorder->setText(QCoreApplication::translate("EditItemDialog", "Reorder?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditItemDialog: public Ui_EditItemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITITEMDIALOG_H
