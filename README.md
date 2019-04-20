<div align=center><img src="https://skyfackr.github.io/cdn/github_project/QtAuic/QTAUIC_logo.ico" width = "128" height = "128" alt="QtAuic">
<p></p>
<h1 class="title-article">QtAuic</h1>
<h5><small>Powered By.Sky_Fackr</small><h5>
<h4>在Qt项目编译前自动更新你的所有ui_xxx.h</h4>
<h4>Update your ui_xxx.h before you build a Qt project<h4>
</div>
<small>*注意：使用前需要将对应的uic.exe加入系统变量，否则可能引发未知错误，目前考虑使用情况暂不打算修复，如果需要可以自己写或者提issue催本鸽
<br>
*warning:It is necessary to add the corresponding uic.exe into the system variables before using it, otherwise it may cause unknown errors. At present, considering the usage situation, it is not intended to repair it.If you really need to use it, please submit issue to inform the author that someone needs it.</small>
<br><br>
<big>语言/Language:<h3>中文</h3>  <h3>English</h3></big><br>
<a name="chinese"></a>
欢迎使用QtAuic！

本程序如题所见，可以用于在Qt项目编译前自动更新你的所有ui_xxx.h，主要为了vs环境下使用

在使用前，请务必设置正确的系统环境变量。请在windows下使用。

特别功能：

1. 自动检测目标目录下所有的xxx.ui并自动执行uic.exe并将结果导入同目录下对应的ui_xxx.h

2. 支持自定义设置，允许设置在不同目录下（目前仅支持一个目录），允许自定义黑白名单

3. 全程自动，启动时没有干扰，可以放在vs中自动执行

使用方法（以vs2017为例）

1. 进属性

2. 进入生成事件->生成前事件

3. 在命令行中填入本程序的启动命令（无需添加任何参数，其实加了也没用）

4. 启动：在生成中使用

自定义设置使用方法：

1. 在QtAuic同目录下创建名为qtauic_setfile.json的文本文件（目录与名称务必不能错）

2. 在json中加入设置

3. 设置列表：

    1. road:string值，表示目标目录，支持相对路径与绝对路径，但是同时只能有一个
   
    2. listmode：string值，只允许是“black”或者“white”，分别对应黑名单，白名单
   
    3. list：array值，放名单列表（可能有bug，由于作者暂时不用这个功能而且作者想咕，所以要用可以issue，初步估计有不能是空的.仅支持绝对路径名称两个bug）
   
4. 注意：三个设置目前版本一个都不能少，否则会转换成默认设置，可能在后续版本修复

5. <a herf="https://skyfackr.github.io/cdn/github_project/QtAuic/simple_qtauic_setfile.json">样例</a>

<a name="english"></a>

Welcome to use this!

Because the author's English is too poor, so there is no English for the time being. Please wait for the author's English score to be updated (that is impossible,hiahiahia).