//此为备份


// #include <opencv2/opencv.hpp>
// #include <iostream>

// int main() {
//     // 读取彩色图像
//     cv::Mat image = cv::imread("/home/panchant/Developing Software/Git/repo/XJTU-RMV-Task02/opencv_project/resources/test_image.png");
//     if (image.empty()) {
//         std::cerr << "Error: Unable to open image file!" << std::endl;
//         return -1;
//     }

//     // // 转换为灰度图像
//     // cv::Mat grayImage;
//     // cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
 
//     // // 保存或显示灰度图像
//     // cv::imwrite("gray_image.jpg", grayImage);
//     // cv::imshow("Gray Image", grayImage);
    
//     //转换为 HSV 图像
//     cv::Mat hsvImage;
//     cv::cvtColor(image, hsvImage, cv::COLOR_BGR2HSV);

//     // 保存或显示 HSV 图像
//     cv::imwrite("hsv_image.jpg", hsvImage);
//     cv::imshow("HSV Image", hsvImage);

//     // // 创建用于存储滤波结果的 Mat 对象
//     // cv::Mat meanBlurredImage;
//     // cv::Mat gaussianBlurredImage;

//     // // 应用均值滤波
//     // // 参数: 输入图像, 输出图像, 核的大小
//     // cv::blur(image, meanBlurredImage, cv::Size(5, 5)); // 5x5 核

//     // // 应用高斯滤波
//     // // 参数: 输入图像, 输出图像, 核的大小, 标准差 (X方向, Y方向)
//     // cv::GaussianBlur(image, gaussianBlurredImage, cv::Size(5, 5), 1.5, 1.5); // 5x5 核，标准差1.5

//     // // 保存均值滤波后的图像
//     // if (!cv::imwrite("mean_blurred_image.jpg", meanBlurredImage)) {
//     //     std::cerr << "Error: Unable to save mean blurred image!" << std::endl;
//     //     return -1;
//     // }

//     // // 保存高斯滤波后的图像
//     // if (!cv::imwrite("gaussian_blurred_image.jpg", gaussianBlurredImage)) {
//     //     std::cerr << "Error: Unable to save gaussian blurred image!" << std::endl;
//     //     return -1;
//     // }

//     // // 显示原图像、均值滤波图像和高斯滤波图像
//     // cv::imshow("Original Image", image);
//     // cv::imshow("Mean Blurred Image", meanBlurredImage);
//     // cv::imshow("Gaussian Blurred Image", gaussianBlurredImage);

//     // 定义红色的 HSV 范围
//     cv::Scalar lowerRed1(0, 100, 100); // 红色的下限（范围1）
//     cv::Scalar upperRed1(10, 255, 255); // 红色的上限（范围1）

//     cv::Scalar lowerRed2(160, 100, 100); // 红色的下限（范围2）
//     cv::Scalar upperRed2(180, 255, 255); // 红色的上限（范围2）

//     // 创建掩模
//     cv::Mat mask1, mask2, mask;

//     // 提取红色区域的掩模（范围1）
//     cv::inRange(hsvImage, lowerRed1, upperRed1, mask1);
    
//     // 提取红色区域的掩模（范围2）
//     cv::inRange(hsvImage, lowerRed2, upperRed2, mask2);

//     // 合并两个掩模
//     cv::add(mask1, mask2, mask);

//     // 使用掩模提取红色区域
//     cv::Mat redRegion;
//     cv::bitwise_and(image, image, redRegion, mask);

//     // 保存掩模和提取的红色区域
//     if (!cv::imwrite("red_mask.jpg", mask)) {
//         std::cerr << "Error: Unable to save red mask image!" << std::endl;
//         return -1;
//     }

//     if (!cv::imwrite("red_region.jpg", redRegion)) {
//         std::cerr << "Error: Unable to save red region image!" << std::endl;
//         return -1;
//     }

//     // 显示原图像、掩模和红色区域
//     cv::imshow("Original Image", image);
//     cv::imshow("Red Mask", mask);
//     cv::imshow("Red Region", redRegion);

//     // 查找轮廓
//     std::vector<std::vector<cv::Point>> contours;
//     std::vector<cv::Vec4i> hierarchy;
//     cv::findContours(mask, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

//     // 绘制轮廓
//     cv::Mat contourImage = image.clone();
//     cv::drawContours(contourImage, contours, -1, cv::Scalar(0, 255, 0), 2);

//     // 显示图像
//     cv::imshow("Contours", contourImage);

//     // 创建用于绘制边界框的图像
//     cv::Mat boundingBoxImage = image.clone();

//     for (const auto& contour : contours) {
//         // 计算边界框
//         cv::Rect boundingBox = cv::boundingRect(contour);

//         // 计算轮廓面积
//         double area = cv::contourArea(contour);

//         // 绘制边界框
//         cv::rectangle(boundingBoxImage, boundingBox, cv::Scalar(0, 255, 0), 2);

//         // 准备文本信息
//         std::string text = "Area: " + std::to_string(static_cast<int>(area));

//         // 设置字体、大小和粗细
//         int fontFace = cv::FONT_HERSHEY_SIMPLEX;
//         double fontScale = 0.8;
//         int thickness = 2;

//         // 计算文本大小
//         int baseline;
//         cv::Size textSize = cv::getTextSize(text, fontFace, fontScale, thickness, &baseline);

//         // 设置文本背景矩形
//         cv::Rect textRect(boundingBox.tl(), cv::Size(textSize.width, textSize.height + baseline));
//         cv::rectangle(boundingBoxImage, textRect, cv::Scalar(0, 0, 0), cv::FILLED);

//         // 绘制文本
//         cv::putText(boundingBoxImage, text, boundingBox.tl() + cv::Point(0, textSize.height), fontFace, fontScale, cv::Scalar(255, 255, 255), thickness);
//     }
    

//     // 显示图像
//     cv::imshow("Bounding Boxes", boundingBoxImage);

//     //提取颜色区域
//     cv::Mat colorRegion;
//     cv::bitwise_and(image, image, colorRegion, mask);

//     // 将提取的颜色区域转换为灰度图像
//     cv::Mat grayImage;
//     cv::cvtColor(colorRegion, grayImage, cv::COLOR_BGR2GRAY);

//     // 应用二值化
//     cv::Mat binaryImage;
//     cv::threshold(grayImage, binaryImage, 127, 255, cv::THRESH_BINARY);

//     // 显示灰度图像和二值化图像
//     cv::imshow("Gray Image", grayImage);
//     cv::imshow("Binary Image", binaryImage);

//     // 应用膨胀
//     cv::Mat dilatedImage;
//     cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
//     cv::dilate(binaryImage, dilatedImage, kernel);

//     // 显示膨胀图像
//     cv::imshow("Dilated Image", dilatedImage);
    
//     // 应用腐蚀
//     cv::Mat erodedImage;
//     cv::erode(dilatedImage, erodedImage, kernel);

//     // 显示腐蚀图像
//     cv::imshow("Eroded Image", erodedImage);

//     // 漫水填充处理
//     cv::Mat filledImage;
//     cv::Mat markers = cv::Mat::zeros(binaryImage.size(), CV_32S);
//     cv::Mat visited = cv::Mat::zeros(binaryImage.size(), CV_8UC1);

//     // 设定标记区域
//     markers.setTo(0);
//     for (int y = 0; y < binaryImage.rows; ++y) {
//         for (int x = 0; x < binaryImage.cols; ++x) {
//             if (binaryImage.at<uchar>(y, x) == 255) {
//                 markers.at<int>(y, x) = 1; // 设置标记
//             }
//         }
//     }

//     // 漫水填充
//     cv::watershed(image, markers);

//     // 将标记图像转为二值图像
//     cv::normalize(markers, filledImage, 0, 255, cv::NORM_MINMAX);
//     filledImage.convertTo(filledImage, CV_8UC1);

//     // 显示漫水填充图像
//     cv::imshow("Filled Image", filledImage);

//         // 绘制任意圆形
//     cv::Point circleCenter(100, 100); // 圆心位置 (根据你的图像调整)
//     int circleRadius = 50;           // 圆的半径
//     cv::Scalar circleColor(0, 255, 0); // 圆的颜色 (绿色)
//     cv::circle(image, circleCenter, circleRadius, circleColor, 2); // 绘制圆形边框

//     // 绘制任意方形
//     cv::Point topLeft(200, 50);     // 方形左上角位置 (根据你的图像调整)
//     int squareSide = 100;           // 方形的边长
//     cv::Scalar squareColor(255, 0, 0); // 方形的颜色 (红色)
//     cv::rectangle(image, topLeft, cv::Point(topLeft.x + squareSide, topLeft.y + squareSide), squareColor, 2); // 绘制方形边框

//     // 绘制文字
//     std::string text = "OpenCV Drawing";
//     cv::Point textOrg(50, 300);      // 文字的起始位置 (根据你的图像调整)
//     int fontFace = cv::FONT_HERSHEY_SIMPLEX; // 字体
//     double fontScale = 1;           // 字体缩放比例
//     cv::Scalar textColor(255, 255, 255); // 文字颜色 (白色)
//     int thickness = 2;              // 字体粗细
//     cv::putText(image, text, textOrg, fontFace, fontScale, textColor, thickness);

//     // // 转换为灰度图像用于边缘检测
//     // cv::Mat grayImage;
//     // cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

//     // 边缘检测
//     cv::Mat edges;
//     cv::Canny(grayImage, edges, 100, 200);

//     // 发现轮廓
//     // std::vector<std::vector<cv::Point>> contours;
//     // std::vector<cv::Vec4i> hierarchy;
//     cv::findContours(edges, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

//     // 绘制红色的外轮廓
//     cv::Mat contoursImage = image.clone(); // 克隆图像用于绘制外轮廓
//     for (size_t i = 0; i < contours.size(); ++i) {
//         cv::drawContours(contoursImage, contours, (int)i, cv::Scalar(0, 0, 255), 2); // 绘制红色轮廓
//     }

//     // // 绘制红色的 bounding box
//     // cv::Mat boundingBoxImage = image.clone(); // 克隆图像用于绘制 bounding box
//     for (size_t i = 0; i < contours.size(); ++i) {
//         cv::Rect boundingBox = cv::boundingRect(contours[i]);
//         cv::rectangle(boundingBoxImage, boundingBox, cv::Scalar(0, 0, 255), 2); // 绘制红色边界框
//     }


//     // 显示结果
//     cv::imshow("Contours Image", contoursImage);
//     cv::imshow("Bounding Box Image", boundingBoxImage);

//     // 图像旋转 35 度
//     double angle = 35.0; // 旋转角度
//     cv::Point2f center(image.cols / 2.0, image.rows / 2.0); // 图像中心点
//     cv::Mat rotationMatrix = cv::getRotationMatrix2D(center, angle, 1.0); // 计算旋转矩阵
//     cv::Mat rotatedImage;
//     cv::warpAffine(image, rotatedImage, rotationMatrix, image.size()); // 应用旋转矩阵

//     // 显示旋转后的图像
//     cv::imshow("Rotated Image", rotatedImage);

//     // 图像裁剪为原图的左上角 1/4
//     int width = image.cols / 2;  // 原图宽度的一半
//     int height = image.rows / 2; // 原图高度的一半
//     cv::Rect roi(0, 0, width, height); // 裁剪区域的矩形
//     cv::Mat croppedImage = image(roi); // 从原图中裁剪出区域

//     // 显示裁剪后的图像
//     cv::imshow("Cropped Image", croppedImage);

    
//     // 等待用户按键
//     cv::waitKey(0);

//     // 关闭所有 OpenCV 窗口
//     cv::destroyAllWindows();

//     return 0;


// }