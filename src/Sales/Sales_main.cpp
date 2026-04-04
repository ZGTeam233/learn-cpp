/*
 * Created by Zilin Zheng on 2026/4/4.
 * 免责声明见: ./Disclaimer.md
 */

#include <iostream>
#include "Sales_item.h"

using namespace std;

int main() {
    Sales_item total; // 保存和的变量

    // 读入第一笔交易，并确保有数据可以处理
    if (cin >> total) {
        Sales_item trans;

        // 读入剩余的交易
        while (cin >> trans) {
            // 如果我们仍在处理相同的书
            if (total.isbn() == trans.isbn())
                total += trans; // 更新总销售额
            else {
                // 输出前一本书的结果
                cout << total << endl;
                total = trans; // total现在表示下一本书的销售额
            }
        }
        cout << total << endl; // 输出最后一本书的结果
    } else {
        // 没有输入，给出提示
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}