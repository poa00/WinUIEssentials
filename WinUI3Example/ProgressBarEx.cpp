#include "pch.h"
#include "ProgressBarEx.h"
#if __has_include("ProgressBarEx.g.cpp")
#include "ProgressBarEx.g.cpp"
#endif
#include <winrt/Microsoft.UI.Xaml.Hosting.h>
namespace winrt::WinUI3Example::implementation
{
    winrt::Microsoft::UI::Xaml::DependencyProperty ProgressBarEx::s_colorProperty = winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
        L"Color",
        winrt::xaml_typename<winrt::Windows::UI::Color>(),
        winrt::xaml_typename<class_type>(),
        winrt::Microsoft::UI::Xaml::PropertyMetadata{ winrt::box_value(winrt::Microsoft::UI::Colors::Green()), &ProgressBarEx::onColorPropertyChanged }
    );

    winrt::Microsoft::UI::Xaml::DependencyProperty ProgressBarEx::s_percentProperty = winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
        L"Percent",
        winrt::xaml_typename<double>(),
        winrt::xaml_typename<class_type>(),
        winrt::Microsoft::UI::Xaml::PropertyMetadata{ winrt::box_value(0.0), &ProgressBarEx::onPercentPropertyChanged}
    );
    void ProgressBarEx::OnApplyTemplate()
    {
        auto border = GetTemplateChild(L"RootBorder").as<winrt::Microsoft::UI::Xaml::Controls::Border>();
        m_compositor = winrt::Microsoft::UI::Xaml::Hosting::ElementCompositionPreview::GetElementVisual(border).Compositor();


        setColor();
        auto gradientBrush = m_compositor.CreateLinearGradientBrush();
        for (auto& gradient : m_gradients)
        {
            gradientBrush.ColorStops().Append(gradient);
        }

        m_spriteVisual = m_compositor.CreateSpriteVisual();
        setSpriteSize();
        m_spriteVisual.Brush(gradientBrush);

        auto const offset = -7.f;
        auto startPointAnimation = m_compositor.CreateVector2KeyFrameAnimation();
        startPointAnimation.Duration(std::chrono::milliseconds{ 1600 });
        startPointAnimation.IterationBehavior(winrt::Microsoft::UI::Composition::AnimationIterationBehavior::Forever);
        startPointAnimation.InsertKeyFrame(0.0f, { offset, 0.0f });
        startPointAnimation.InsertKeyFrame(1.0f, {});

        auto endPointAnimation = m_compositor.CreateVector2KeyFrameAnimation();
        endPointAnimation.Duration(startPointAnimation.Duration());
        endPointAnimation.IterationBehavior(startPointAnimation.IterationBehavior());
        endPointAnimation.InsertKeyFrame(0.0f, { 1.0f, 0.0f });
        endPointAnimation.InsertKeyFrame(1.0f, { -offset, 0.0f });

        gradientBrush.StartAnimation(L"StartPoint", startPointAnimation);
        gradientBrush.StartAnimation(L"EndPoint", endPointAnimation);
        winrt::Microsoft::UI::Xaml::Hosting::ElementCompositionPreview::SetElementChildVisual(border, m_spriteVisual);
        SizeChanged([this](auto...)
            {
                setSpriteSize();
            });
    }
    winrt::Windows::UI::Color ProgressBarEx::Color()
    {
        return winrt::unbox_value_or<winrt::Windows::UI::Color>(s_colorProperty, winrt::Windows::UI::Colors::Green());
    }
    void ProgressBarEx::Color(winrt::Windows::UI::Color value)
    {
        SetValue(s_colorProperty, winrt::box_value(value));
    }
    winrt::Microsoft::UI::Xaml::DependencyProperty ProgressBarEx::ColorProperty()
    {
        return s_colorProperty;
    }
    double ProgressBarEx::Percent()
    {
        return winrt::unbox_value<double>(GetValue(s_percentProperty));
    }
    void ProgressBarEx::Percent(double value)
    {
        SetValue(s_percentProperty, winrt::box_value(std::clamp(value, 0.0, 1.0)));
    }
    winrt::Microsoft::UI::Xaml::DependencyProperty ProgressBarEx::PercentProperty()
    {
        return s_percentProperty;
    }

    void ProgressBarEx::onColorPropertyChanged(winrt::Microsoft::UI::Xaml::DependencyObject const& d, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
    {
        winrt::get_self<ProgressBarEx>(d.as<class_type>())->setColor();
    }
    void ProgressBarEx::onPercentPropertyChanged(winrt::Microsoft::UI::Xaml::DependencyObject const& d, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
    {
        winrt::get_self<ProgressBarEx>(d.as<class_type>())->setSpriteSize();
    }
    void ProgressBarEx::setColor()
    {
        auto color = Color();
        m_gradients[0] = m_compositor.CreateColorGradientStop(0.273f, winrt::Windows::UI::ColorHelper::FromArgb(50, color.R, color.G, color.B));
        m_gradients[1] = m_compositor.CreateColorGradientStop(0.436f, winrt::Windows::UI::ColorHelper::FromArgb(100, color.R, color.G, color.B));
        m_gradients[2] = m_compositor.CreateColorGradientStop(0.482f, winrt::Windows::UI::ColorHelper::FromArgb(100, color.R, color.G, color.B));
        m_gradients[3] = m_compositor.CreateColorGradientStop(0.643f, winrt::Windows::UI::ColorHelper::FromArgb(50, color.R, color.G, color.B));
    }
    void ProgressBarEx::setSpriteSize()
    {
        if(m_compositor && m_spriteVisual)
            m_spriteVisual.Size({ static_cast<float>(ActualWidth() * Percent()), static_cast<float>(ActualHeight()) });
    }
}
