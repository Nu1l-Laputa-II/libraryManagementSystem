# 图书管理系统 (Library Management System)

一个基于C语言开发的命令行图书管理系统，提供图书和读者管理、借阅服务等功能。

## 目录
- [功能特点](#功能特点)
- [系统架构](#系统架构)
- [开发环境](#开发环境)
- [安装说明](#安装说明)
- [使用说明](#使用说明)
- [项目结构](#项目结构)
- [数据存储](#数据存储)
- [开发文档](#开发文档)

## 功能特点

### 图书管理
- 添加新图书到系统
- 从系统中删除图书
- 查找特定图书
- 显示所有图书信息
- 跟踪图书库存和可借数量

### 读者管理
- 添加新读者
- 删除读者信息
- 查找读者信息
- 显示所有读者
- 跟踪读者借阅数量

### 借阅服务
- 图书借出处理
- 图书归还处理
- 自动更新图书和读者状态

### 数据持久化
- 自动保存所有数据
- 程序启动时自动加载数据
- 二进制文件存储

## 系统架构

系统采用模块化设计，主要包含以下模块：
- 图书管理模块 (book_management)
- 读者管理模块 (reader_management)
- 数据结构定义 (structures)
- 主程序模块 (main)

## 开发环境

- 操作系统：Windows/Linux/MacOS
- 编程语言：C语言
- 编译器要求：gcc 4.8+
- 构建工具：make (可选)

## 安装说明

1. 克隆代码仓库：
```bash
git clone https://github.com/Nu1l-Laputa-II/libraryManagementSystem.git
cd libraryManagementSystem
```

2. 编译项目：
```bash
# 使用gcc直接编译
gcc main.c book_management.c reader_management.c -o library_system

# 或使用make（如果有Makefile）
make
```

3. 运行程序：
```bash
./library_system
```

## 使用说明

### 主菜单选项
1. 添加图书：输入ISBN、书名、作者、数量
2. 删除图书：通过ISBN删除
3. 查找图书：通过ISBN查找
4. 显示所有图书：查看图书列表
5. 添加读者：输入ID、姓名、电话
6. 删除读者：通过ID删除
7. 显示所有读者：查看读者列表
8. 借书：输入读者ID和图书ISBN
9. 还书：输入读者ID和图书ISBN
0. 退出系统

### 使用示例
```text
1. 添加图书
输入 ISBN: 9787111111111
输入书名: C程序设计
输入作者: 张三
输入数量: 5

2. 添加读者
输入读者ID: 1001
输入姓名: 李四
输入电话: 13800138000

3. 借书
输入读者ID: 1001
输入图书ISBN: 9787111111111
```

## 项目结构

```
libraryManagementSystem/
├── main.c              # 主程序
├── structures.h        # 数据结构定义
├── book_management.h   # 图书管理模块头文件
├── book_management.c   # 图书管理模块实现
├── reader_management.h # 读者管理模块头文件
├── reader_management.c # 读者管理模块实现
├── Makefile           # 构建配置
├── README.md          # 项目说明文档
└── data/              # 数据文件目录
    ├── books.dat      # 图书数据文件
    └── readers.dat    # 读者数据文件
```

## 数据存储

系统使用二进制文件存储数据：
- `books.dat`：存储图书信息
- `readers.dat`：存储读者信息

数据文件格式：
- 开头4字节：记录数量
- 后续数据：结构体数组

## 开发文档

详细的API文档和开发指南请参考：
- [设计文档](doc/design.md)
- [API文档](doc/api.md)

## 注意事项

1. 数据安全
   - 定期备份数据文件
   - 不要手动修改数据文件

2. 使用限制
   - 最大支持1000本图书
   - 最大支持500名读者
   - 字符串长度限制：
     * 书名/作者：50字符
     * ISBN：20字符
     * 电话：20字符

## 作者

[Nu1l-Laputa-II]

## 许可证

MIT License

## 贡献指南

1. Fork 项目
2. 创建特性分支
3. 提交改动
4. 发起 Pull Request

## 问题反馈

如有问题，请提交issue或联系：
- GitHub Issues: [issues page](https://github.com/Nu1l-Laputa-II/libraryManagementSystem/issues)
