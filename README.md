# 使用 C++ 和 OpenCV 进行图像处理  

## 任务要求

### 环境配置

由于先前配置过相关环境，所以此步骤没有任何出错：

![ed6c1db117248a7dda1a8cbcae613522.png](https://ice.frostsky.com/2024/09/17/ed6c1db117248a7dda1a8cbcae613522.png)

### 项目结构

#### 构筑项目结构

通过`mkdir`等指令成功构构筑项目结构：

![f4c7693193762b4de119fc5f4f0116ce.png](https://ice.frostsky.com/2024/09/17/f4c7693193762b4de119fc5f4f0116ce.png)

#### 获取测试图片  
在 `opencv_project` 中使用命令成功下载指定的测试图片至 `resources/` 目录：  

![50eaa9e292b63dfceeeceb243c631145.png](https://ice.frostsky.com/2024/09/17/50eaa9e292b63dfceeeceb243c631145.png)


### 核心实现  

#### CMakeLists.txt编写

编写成功：

![70a4ab7a9ab01564d8dd5b9490b25ccb.png](https://ice.frostsky.com/2024/09/17/70a4ab7a9ab01564d8dd5b9490b25ccb.png)

#### 主程序开发
- 图像颜色空间转换
	- 转化为灰度图，显示如下：![85424c221a15575d7d333bf76cdc0de6.png](https://ice.frostsky.com/2024/09/17/85424c221a15575d7d333bf76cdc0de6.png)  
	- 转化为 HSV 图片,显示如下：![ea8348a9a7c0cc69eeef5520adf8b718.png](https://ice.frostsky.com/2024/09/17/ea8348a9a7c0cc69eeef5520adf8b718.png)
在开发程序过程中，发现总是显示路径错误：（实际运行时没有问题）
![5872a42e6323c3a760ea18a1069c30f9.png](https://ice.frostsky.com/2024/09/17/5872a42e6323c3a760ea18a1069c30f9.png)  

- 应用各种滤波操作
	- 应用均值滤波，显示如下：![5e5c80c7ac4fffd88f13bca0d8e05673.png](https://ice.frostsky.com/2024/09/17/5e5c80c7ac4fffd88f13bca0d8e05673.png)
	- 应用高斯滤波，显示如下：![be3400f4709e4a838cc72f23772743c2.png](https://ice.frostsky.com/2024/09/17/be3400f4709e4a838cc72f23772743c2.png)

- 特征提取
	- 提取红色颜色区域
	    - HSV 方法，显示如下：
	    1. 掩模区域：![53888661748948f2e67df090a4881d75.png](https://ice.frostsky.com/2024/09/17/53888661748948f2e67df090a4881d75.png)   
		2.  红色区域：  ![bbe43e62cab2423061a99896e68b3b02.png](https://ice.frostsky.com/2024/09/17/bbe43e62cab2423061a99896e68b3b02.png)
	- 寻找图像中红色的外轮廓，显示如下：![a2aa024100076c97f7567bb158f3dd46.png](https://ice.frostsky.com/2024/09/17/a2aa024100076c97f7567bb158f3dd46.png)
	- 寻找图像中红色的 bounding box，显示如下：![a7a86b4694e3ca1382f01f6aa7c6d40e.png](https://ice.frostsky.com/2024/09/17/a7a86b4694e3ca1382f01f6aa7c6d40e.png)
	- 计算轮廓的面积，显示如下：（修改后与bounding box重合）![ad871d3c635215f2454426814c7789e6.png](https://ice.frostsky.com/2024/09/17/ad871d3c635215f2454426814c7789e6.png)
	- 提取高亮颜色区域并进行图形学处理
		- 灰度化，显示如下：![1b1087d6d46fbc0835ca798b4729c944.png](https://ice.frostsky.com/2024/09/17/1b1087d6d46fbc0835ca798b4729c944.png)
		- 二值化，显示如下：![861dc0e753c66d5425d94e48acc7ebc4.png](https://ice.frostsky.com/2024/09/17/861dc0e753c66d5425d94e48acc7ebc4.png)
		- 膨胀，显示如下：![aaa53865787f0a7d769147fe663b2671.png](https://ice.frostsky.com/2024/09/17/aaa53865787f0a7d769147fe663b2671.png)
		- 腐蚀，显示如下：![ffb40a54873ce8ddee18f67f49bfec81.png](https://ice.frostsky.com/2024/09/17/ffb40a54873ce8ddee18f67f49bfec81.png)
		- 对处理后的图像进行漫水处理，显示如下：(经过这一系列操作，最后漫水填充变成了一片空白)![7f0717547f367fcf9cc94cf55bd417f9.png](https://ice.frostsky.com/2024/09/17/7f0717547f367fcf9cc94cf55bd417f9.png)
	- 图像绘制
		- 绘制任意圆形方形和文字
		- 绘制红色的外轮廓，两者共同显示如下：![815442c431c3d8d07ebfd2cde83cec42.png](https://ice.frostsky.com/2024/09/17/815442c431c3d8d07ebfd2cde83cec42.png)
		- 绘制红色的 bounding box，显示如下：![ec15efba80f9cabe70a464155b62aade.png](https://ice.frostsky.com/2024/09/17/ec15efba80f9cabe70a464155b62aade.png)
	- 对图像进行处理
		- 图像旋转 35 度，显示如下：![a3c3912fccc5cd323e29e16d13944933.png](https://ice.frostsky.com/2024/09/17/a3c3912fccc5cd323e29e16d13944933.png)
		- 图像裁剪为原图的左上角 1/4，显示如下：![fc11ba96ffd46eed3fe609db13d8cdbd.png](https://ice.frostsky.com/2024/09/17/fc11ba96ffd46eed3fe609db13d8cdbd.png)

---

# 完成思路

1. 主要完成方法是通过询问GPT，达到先调用，后熟悉，再学习OpenCV的过程。但是截至目前，还停留在熟悉的过程。在使用GPT过程中最大的问题是如何用通俗，直观，易于GPT理解的语言去阐述自己的问题。经过学习，发现更深入的研究，带来更专业的术语，更精准的词汇可以使GPT回答质量大幅提升。*例如：*![c7f766508884c8bede7311cfca5ac80e.png](https://ice.frostsky.com/2024/09/17/c7f766508884c8bede7311cfca5ac80e.png)（给的地址越准确，如：*文件夹路径*，回答的就更准确；给的地址越模糊，如：*`上面的文件夹`*，就很容易出漏洞
1. 通过B站教程，查漏补缺，*例：* [【2022B站最好的OpenCV课程推荐】](https://www.bilibili.com/video/BV1PV411774y/?spm_id_from=333.337.search-card.all.click&vd_source=0c3d3cdac50edbb48aae89afac63ffe7)