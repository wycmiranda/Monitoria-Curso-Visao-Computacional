#include<opencv2/opencv.hpp>
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float src_data[] = {1, 3, 5, 4, 2};
    float kernel_data[] = {3, 2, 1};

    cv::Mat src(1, 5, CV_32FC1, src_data);
    cv::Mat kernel(1, 3, CV_32FC1, kernel_data);

    cv::Mat result;
    cv::filter2D(src, result, src.depth(), kernel);

    src.convertTo(src, CV_8UC1);
    kernel.convertTo(kernel, CV_8UC1);
    result.convertTo(result, CV_8UC1);

    std::string janelas[] = { "Imagem","Kernel", "Convolution" };
    cv::namedWindow(janelas[0], cv::WINDOW_GUI_NORMAL);
    cv::namedWindow(janelas[1], cv::WINDOW_GUI_NORMAL);
    cv::namedWindow(janelas[2], cv::WINDOW_GUI_NORMAL);

    cv::imshow(janelas[0], src);
    cv::imshow(janelas[1], kernel);
    cv::imshow(janelas[2], result);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
    
}
