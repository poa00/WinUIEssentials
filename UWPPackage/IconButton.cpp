#include "pch.h"
#include "IconButton.h"
#if __has_include("IconButton.g.cpp")
#include "IconButton.g.cpp"
#endif


namespace winrt::UWPPackage::implementation
{
	winrt::Windows::UI::Xaml::DependencyProperty IconButton::m_iconProperty =
		winrt::Windows::UI::Xaml::DependencyProperty::Register(
			L"Icon",
			winrt::xaml_typename<winrt::Windows::Foundation::IInspectable>(),
			winrt::xaml_typename<winrt::UWPPackage::IconButton>(),
			nullptr
		);

	IconButton::IconButton()
	{
		RegisterPropertyChangedCallback(winrt::Windows::UI::Xaml::Controls::ContentControl::ContentProperty(),
			[this](auto...)
			{
				m_firstWidth.reset();
				if (m_loaded)
				{
					m_contentPresenter.Width(NAN);
				}
			});
	}

	void IconButton::OnApplyTemplate()
	{
		base_type::OnApplyTemplate();

		auto rootButton = GetTemplateChild(L"RootButton").as<winrt::Windows::UI::Xaml::Controls::Primitives::ButtonBase>();

		rootButton.PointerEntered([this](auto...)
			{
				//winrt::Windows::UI::Xaml::VisualStateManager::GoToState(*this, L"Enter", true);
				if (!m_storyboard)
				{
					m_storyboard = {};
					m_storyboard.Duration({ duration, winrt::Windows::UI::Xaml::DurationType::TimeSpan });
					m_storyboard.Children().Append(m_widthAnimation);

					winrt::Windows::UI::Xaml::Media::Animation::DoubleAnimation opacityAnimation;
					opacityAnimation.From(0.0);
					opacityAnimation.To(1.0);
					opacityAnimation.Duration({ duration, winrt::Windows::UI::Xaml::DurationType::TimeSpan });
					winrt::Windows::UI::Xaml::Media::Animation::Storyboard::SetTarget(opacityAnimation, m_contentPresenter);
					winrt::Windows::UI::Xaml::Media::Animation::Storyboard::SetTargetProperty(
						opacityAnimation,
						L"Opacity"
					);
					m_storyboard.Children().Append(opacityAnimation);
				}
				m_storyboard.AutoReverse(false);
				m_contentPresenter.Visibility(winrt::Windows::UI::Xaml::Visibility::Visible);
				m_storyboard.Begin();
			});
		rootButton.PointerExited([this](auto...)
			{
				//winrt::Windows::UI::Xaml::VisualStateManager::GoToState(*this, L"PointerExit", true);
				if (!m_storyboard)
					return;

				m_storyboard.AutoReverse(true);
				m_storyboard.Begin();
				//m_storyboard.Resume();
				m_storyboard.Seek(duration);
			});
		rootButton.Click([this](auto sender, auto&&...args)
			{
				m_handlers(*this, args...);
			});

		m_contentPresenter = GetTemplateChild(L"ContentPresenter").as<winrt::Windows::UI::Xaml::Controls::ContentPresenter>();

		m_contentPresenter.Loaded([this](auto...) { m_loaded = true; });

		m_contentPresenter.SizeChanged([this](auto, winrt::Windows::UI::Xaml::SizeChangedEventArgs const& args)
			{
				if (!m_widthAnimation)
				{
					m_widthAnimation = {};
					winrt::Windows::UI::Xaml::Media::Animation::Storyboard::SetTarget(m_widthAnimation, m_contentPresenter);
					winrt::Windows::UI::Xaml::Media::Animation::Storyboard::SetTargetProperty(
						m_widthAnimation,
						L"(ContentPresenter.Width)"
					);
					m_widthAnimation.EnableDependentAnimation(true);
					m_widthAnimation.From(0.0);

					winrt::Windows::UI::Xaml::Media::Animation::ExponentialEase easing;
					easing.Exponent(7.);
					easing.EasingMode(winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseOut);
					m_widthAnimation.EasingFunction(easing);
				}


				if (!m_firstWidth)
				{
					m_contentPresenter.Width(0);
				}
				else
				{
					return;
				}

				if (m_storyboard && m_storyboard.GetCurrentState() == winrt::Windows::UI::Xaml::Media::Animation::ClockState::Active)
					return;
				m_widthAnimation.To(args.NewSize().Width);
				m_firstWidth = args.NewSize().Width;
				m_widthAnimation.Duration({ duration, winrt::Windows::UI::Xaml::DurationType::TimeSpan });
			});
	}

	winrt::Windows::Foundation::IInspectable IconButton::Icon()
	{
		return GetValue(m_iconProperty);
	}

	void IconButton::Icon(winrt::Windows::Foundation::IInspectable value)
	{
		SetValue(m_iconProperty, value);
	}

	winrt::Windows::UI::Xaml::DependencyProperty IconButton::IconProperty()
	{

		return m_iconProperty;
	}
	winrt::event_token IconButton::Click(winrt::Windows::UI::Xaml::RoutedEventHandler const& handler)
	{
		return m_handlers.add(handler);
	}
	void IconButton::Click(event_token const& cookie)
	{
		GetTemplateChild(L"RootButton").as<winrt::Windows::UI::Xaml::Controls::Primitives::ButtonBase>().Click(cookie);
	}
	void IconButton::Collapse()
	{
	}
	void IconButton::Expand()
	{
	}
	bool IconButton::IsExpanded()
	{
		return false;
	}
	void IconButton::IsExpanded(bool value)
	{
	}
	winrt::Windows::UI::Xaml::DependencyProperty IconButton::IsExpandedProperty()
	{
		return winrt::Windows::UI::Xaml::DependencyProperty{ nullptr };
	}
}
