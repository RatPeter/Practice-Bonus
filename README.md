## 一、在Ubuntu系统下利用GCC、GSL、Gnuplot进行科学编程

*Ubuntu（友帮拓、优般图、乌班图）是一个以桌面应用为主的开源GNU/Linux操作系统，目前广泛应用于个人电脑,IoT/智能物联网,容器,服务器和云端上。*

*GNU科学库（GSL）是C和C ++程序员的数字库。该库提供了广泛的数学例程，如随机数生成器，特殊函数和最小二乘拟合等。GSL是GNU项目的一部分，是GNU通用公共许可证下的免费软件。*

*Gnuplot是一个可移植的命令行驱动的图形实用程序，适用于Linux，OS / 2，MS Windows，OSX，VMS和许多其他平台。*

**1、使用GSL对文件数据进行线性回归**

在C文件中，通过标准库函数fgets（）读取spring_data.csv中的数据文件，并将读取后的数据经处理后存放于x[] ,y[]两个数组中。

调用GSL库函数，通过gsl_fit_linear（）函数实现数据的线性回归并输出相应的数据计算结果。

**2、使用Gnuplot实现数据和线性回归结果可视化**

为实现在C/C++中使用Gnuplot进行绘图，使用Pipe和popen（）函数来连接子程序获取数据，并结合GSL的线性回归结果，调用相应语句实现绘图和输出。

**3、具体实现**

借助GCC，编写makefile文件，在Ubuntu系统下实现将源文件转化为可执行文件，并运行输出相应的数据和图片结果，过程及结果如下：
![image](/img/P1.png)

![image](/img/P2.png)

![image](/img/P3.png)



## 二、使用Git，Github实现版本控制

*在任何软件开发中，最重要的工具之一是版本控制软件。版本控制几乎适用于任何数字内容，因此它不仅限于软件开发，且对于原稿文件，图形，数据和笔记本也非常有用。*

**1、本地Git和远程Github版本控制的初始化**

在本地安装Git、远程建立Github账户，并 配置Git本地用户名和email(和Github账户一致）。
![image](/img/P4.png)

**2、使用Git对本地项目进行版本控制**

初始化本地项目的Git版本控制，并提交工作内容到Git仓库，实现在项目根目录下创建一个名为.git的隐藏子目录，其中包含所有Git相关数据。

![image](/img/P5.png)

**3、本地仓库的远程Github仓库初始化**

在Github账户中建立一个和本地项目目录同名的空仓库（不能有README.md等任何内容），将远程Github仓库加为本Git项目的远程源，并首次推送本地仓库到远程Github仓库。所建立的远程Github仓库的网址为：https://github.com/RatPeter/Practice-Bonus 。
![image](/img/P6.png)

**4、本地仓库工作内容变化更新、同步到远程github**

将本地工作内容变化提交到暂存区，存入暂存区内容提交至本地仓库，最终本地仓库的更新同步到远程github仓库。
![image](/img/P7.png)

最终的仓库截图如下：
![image](/img/P8.png)