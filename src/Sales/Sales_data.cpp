#include <iostream>
#include <string>
#include "Sales_data.h"

double Sales_data::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold; // 叠加销售数量
    revenue += rhs.revenue;       // 叠加销售收入
    return *this;                // 返回对象本身
}

std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs; // 复制左操作数到sum中
    sum.combine(rhs);     // 将右操作数的数据添加到sum中
    return sum;          // 返回sum
}

Sales_data::Sales_data(std::istream &is) {
    read(is, *this); // 将is绑定到当前对象并从中读取数据
}