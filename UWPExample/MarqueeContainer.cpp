﻿#include "pch.h"
#include "MarqueeContainer.h"
#if __has_include("MarqueeContainer.g.cpp")
#include "MarqueeContainer.g.cpp"
#endif
#include <winrt/Windows.UI.Xaml.Input.h>

namespace winrt::UWPExample::implementation
{
    winrt::Windows::UI::Xaml::DependencyProperty MarqueeContainer::m_speedProperty =
        winrt::Windows::UI::Xaml::DependencyProperty::Register(
            L"Speed",
            winrt::xaml_typename<double>(),
            winrt::xaml_typename<UWPExample::MarqueeContainer>(),
            winrt::Windows::UI::Xaml::PropertyMetadata{ winrt::box_value(32.), &MarqueeContainer::propertyChanged }
    );

    winrt::Windows::UI::Xaml::DependencyProperty MarqueeContainer::m_repeatBehaviorProperty =
        winrt::Windows::UI::Xaml::DependencyProperty::Register(
            L"RepeatBehavior",
            winrt::xaml_typename<winrt::Windows::UI::Xaml::Media::Animation::RepeatBehavior>(),
            winrt::xaml_typename<UWPExample::MarqueeContainer>(),
            winrt::Windows::UI::Xaml::PropertyMetadata{
                winrt::box_value(
                    winrt::Windows::UI::Xaml::Media::Animation::RepeatBehaviorHelper::Forever()
                ),
                &MarqueeContainer::propertyChanged
            }
    );

    winrt::Windows::UI::Xaml::DependencyProperty MarqueeContainer::m_behaviorProperty =
        winrt::Windows::UI::Xaml::DependencyProperty::Register(
            L"Behavior",
            winrt::xaml_typename<UWPExample::MarqueeBehavior>(),
            winrt::xaml_typename<UWPExample::MarqueeContainer>(),
            winrt::Windows::UI::Xaml::PropertyMetadata{
                winrt::box_value(UWPExample::MarqueeBehavior{}),
                &MarqueeContainer::behaviorPropertyChanged
            }
    );

    winrt::Windows::UI::Xaml::DependencyProperty MarqueeContainer::m_directionProperty =
        winrt::Windows::UI::Xaml::DependencyProperty::Register(
            L"Direction",
            winrt::xaml_typename<UWPExample::MarqueeDirection>(),
            winrt::xaml_typename<UWPExample::MarqueeContainer>(),
            winrt::Windows::UI::Xaml::PropertyMetadata{
                winrt::box_value(UWPExample::MarqueeDirection::Left),
                &MarqueeContainer::directionPropertyChanged
            }
    );

    winrt::Windows::UI::Xaml::DependencyProperty MarqueeContainer::m_textProperty =
        winrt::Windows::UI::Xaml::DependencyProperty::Register(
            L"Text",
            winrt::xaml_typename<winrt::hstring>(),
            winrt::xaml_typename<UWPExample::MarqueeContainer>(),
            winrt::Windows::UI::Xaml::PropertyMetadata{
                winrt::box_value(L"")
            }
        );

    winrt::Windows::UI::Xaml::DependencyProperty MarqueeContainer::m_pauseOnHoverProperty =
        winrt::Windows::UI::Xaml::DependencyProperty::Register(
            L"PauseOnHover",
            winrt::xaml_typename<winrt::hstring>(),
            winrt::xaml_typename<UWPExample::MarqueeContainer>(),
            winrt::Windows::UI::Xaml::PropertyMetadata{
                winrt::box_value(false),
                &MarqueeContainer::pauseOnHoverChanged
            }
    );

    winrt::Windows::UI::Xaml::DependencyProperty MarqueeContainer::m_intervalSpaceProperty =
        winrt::Windows::UI::Xaml::DependencyProperty::Register(
            L"IntervalSpace",
            winrt::xaml_typename<double>(),
            winrt::xaml_typename<UWPExample::MarqueeContainer>(),
            winrt::Windows::UI::Xaml::PropertyMetadata{
                winrt::box_value(64.),
                &MarqueeContainer::spaceIntervalChanged
            }
    );

    void MarqueeContainer::OnApplyTemplate()
    {
        base_type::OnApplyTemplate();
        auto test = GetTemplateChild(MarqueeContainerPartName);
        marqueeContainer = GetTemplateChild(MarqueeContainerPartName).as<decltype(marqueeContainer)>();
        segment1 = GetTemplateChild(Segment1PartName).as<decltype(segment1)>();
        segment2 = GetTemplateChild(Segment2PartName).as<decltype(segment2)>();
        marqueeTransform = GetTemplateChild(MarqueeTransformPartName).as<decltype(marqueeTransform)>();
        marqueeContainer.SizeChanged({ this, &MarqueeContainer::container_SizeChanged });
        rootGrid = GetTemplateChild(L"RootGrid").as<decltype(rootGrid)>();

        winrt::Windows::UI::Xaml::VisualStateManager::GoToState(*this, getVisualStateName(Direction()), false);
        winrt::Windows::UI::Xaml::VisualStateManager::GoToState(*this, getVisualStateName(Behavior()), false);
    }

    double MarqueeContainer::Speed()
    {
        return winrt::unbox_value<double>(GetValue(m_speedProperty));
    }

    void MarqueeContainer::Speed(double value)
    {
        SetValue(m_speedProperty, winrt::box_value(value));
    }

    winrt::Windows::UI::Xaml::DependencyProperty MarqueeContainer::SpeedProperty()
    {
        return m_speedProperty;
    }

    winrt::Windows::UI::Xaml::Media::Animation::RepeatBehavior MarqueeContainer::RepeatBehavior()
    {
        return winrt::unbox_value<winrt::Windows::UI::Xaml::Media::Animation::RepeatBehavior>(
            GetValue(m_repeatBehaviorProperty)
        );
    }

    void MarqueeContainer::RepeatBehavior(winrt::Windows::UI::Xaml::Media::Animation::RepeatBehavior value)
    {
        SetValue(m_repeatBehaviorProperty, winrt::box_value(value));
    }

    winrt::Windows::UI::Xaml::DependencyProperty MarqueeContainer::RepeatBehaviorProperty()
    {
        return m_repeatBehaviorProperty;
    }

    UWPExample::MarqueeBehavior MarqueeContainer::Behavior()
    {
        return winrt::unbox_value<UWPExample::MarqueeBehavior>(
            GetValue(m_behaviorProperty)
        );
    }

    void MarqueeContainer::Behavior(UWPExample::MarqueeBehavior value)
    {
        SetValue(m_behaviorProperty, winrt::box_value(value));
    }

    winrt::Windows::UI::Xaml::DependencyProperty MarqueeContainer::BehaviorProperty()
    {
        return m_behaviorProperty;
    }

    UWPExample::MarqueeDirection MarqueeContainer::Direction()
    {
        return winrt::unbox_value<UWPExample::MarqueeDirection>(
            GetValue(m_directionProperty)
        );
    }

    void MarqueeContainer::Direction(UWPExample::MarqueeDirection value)
    {
        SetValue(m_directionProperty, winrt::box_value(value));
    }

    winrt::Windows::UI::Xaml::DependencyProperty MarqueeContainer::DirectionProperty()
    {
        return m_directionProperty;
    }

    winrt::hstring MarqueeContainer::Text()
    {
        return winrt::unbox_value<winrt::hstring>(GetValue(m_textProperty));
    }

    void MarqueeContainer::Text(winrt::hstring value)
    {
        SetValue(m_textProperty, winrt::box_value(value));
    }

    winrt::Windows::UI::Xaml::DependencyProperty MarqueeContainer::TextProperty()
    {
        return m_textProperty;
    }

    bool MarqueeContainer::PauseOnHover()
    {
        return winrt::unbox_value<bool>(GetValue(m_pauseOnHoverProperty));
    }

    void MarqueeContainer::PauseOnHover(bool value)
    {
        SetValue(m_pauseOnHoverProperty, winrt::box_value(value));
    }

    winrt::Windows::UI::Xaml::DependencyProperty MarqueeContainer::PauseOnHoverProperty()
    {
        return m_pauseOnHoverProperty;
    }

    double MarqueeContainer::IntervalSpace()
    {
        return winrt::unbox_value<double>(GetValue(m_intervalSpaceProperty));
    }

    void MarqueeContainer::IntervalSpace(double value)
    {
        SetValue(m_intervalSpaceProperty, winrt::box_value(value));
    }

    winrt::Windows::UI::Xaml::DependencyProperty MarqueeContainer::IntervalSpaceProperty()
    {
        return m_intervalSpaceProperty;
    }

    void MarqueeContainer::Pause()
    {
        isPausing = true;
        if (marqueeStoryboard)
        {
            marqueeStoryboard.Pause();
        }
    }

    void MarqueeContainer::Resume()
    {
        isPausing = false;
        resumeStoryboardImpl();
    }

    void MarqueeContainer::Reset()
    {
        if (marqueeStoryboard)
        {
            marqueeStoryboard.Seek({});
            marqueeStoryboard.Begin();
        }
    }

    void MarqueeContainer::propertyChanged(winrt::Windows::UI::Xaml::DependencyObject d, winrt::Windows::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
    {
        if (auto control = d.try_as<UWPExample::MarqueeContainer>())
        {
            winrt::get_self<MarqueeContainer>(control)->updateAnimation(true);
        }
    }

    void MarqueeContainer::behaviorPropertyChanged(winrt::Windows::UI::Xaml::DependencyObject d, winrt::Windows::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
    {
        auto container = d.as<UWPExample::MarqueeContainer>();
        if (!container)
            return;

        auto control = winrt::get_self<MarqueeContainer>(container);
        bool const active = control->isActive;
        auto const newBehavior = winrt::unbox_value<MarqueeBehavior>(e.NewValue());
        winrt::Windows::UI::Xaml::VisualStateManager::GoToState(container, getVisualStateName(newBehavior), true);
        control->stopMarquee(false);
        //if (active)
        //    control->startMarquee();
        control->startMarquee();
    }

    void MarqueeContainer::directionPropertyChanged(winrt::Windows::UI::Xaml::DependencyObject d, winrt::Windows::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
    {
        auto container = d.as<UWPExample::MarqueeContainer>();
        if (!container)
            return;

        auto control = winrt::get_self<MarqueeContainer>(container);
        bool const active = control->isActive;
        auto const oldDirection = winrt::unbox_value<MarqueeDirection>(e.OldValue());
        auto const newDirection = winrt::unbox_value<MarqueeDirection>(e.NewValue());
        auto const oldAxisX = isHorizontal(oldDirection);
        auto const newAxisX = isHorizontal(newDirection);

        winrt::Windows::UI::Xaml::VisualStateManager::GoToState(container, getVisualStateName(newDirection), true);
        if (oldAxisX != newAxisX)
        {
            control->stopMarquee(false);
        }
        //if (active)
        //{
        //    control->startMarquee();
        //}
        control->startMarquee();
    }

    void MarqueeContainer::pauseOnHoverChanged(winrt::Windows::UI::Xaml::DependencyObject d, winrt::Windows::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
    {
        auto container = d.as<UWPExample::MarqueeContainer>();
        if (!container)
            return;

        auto control = winrt::get_self<MarqueeContainer>(container);
        control->PointerEntered(control->pointerEntered_revoker);
        control->PointerExited(control->pointerExited_revoker);
        if (winrt::unbox_value<bool>(e.NewValue()))
        {
            control->pointerEntered_revoker = control->PointerEntered([weakSelf = control->get_weak()](auto...) {
                if (auto strongSelf = weakSelf.get())
                {
                    strongSelf->isHovering = true;
                    strongSelf->marqueeStoryboard.Pause();
                }
            });
            control->pointerExited_revoker = control->PointerExited([weakSelf = control->get_weak()](auto...) {
                if (auto strongSelf = weakSelf.get())
                {
                    strongSelf->isHovering = false;
                    strongSelf->resumeStoryboardImpl();
                }
            });
        }
    }

    void MarqueeContainer::spaceIntervalChanged(winrt::Windows::UI::Xaml::DependencyObject d, winrt::Windows::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
    {
        auto container = d.as<UWPExample::MarqueeContainer>();
        if (!container)
            return;
        auto control = winrt::get_self<MarqueeContainer>(container);
        if (!control->rootGrid || control->Behavior() != MarqueeBehavior::Looping)
            return;

        for (auto visualStateGroup : winrt::Windows::UI::Xaml::VisualStateManager::GetVisualStateGroups(control->rootGrid))
        {
            for (auto visualState : visualStateGroup.States())
            {
                if (visualState.Name() == LoopingVisualStateName)
                {
                    auto const setter = (*visualState.Setters().First()).as<winrt::Windows::UI::Xaml::Setter>();
                    auto const oldPadding = setter.Value().as<winrt::Windows::UI::Xaml::Thickness>();
                    setter.Value(winrt::box_value(winrt::Windows::UI::Xaml::ThicknessHelper::FromLengths(
                        oldPadding.Left,
                        oldPadding.Top,
                        winrt::unbox_value<double>(e.NewValue()),
                        oldPadding.Bottom
                    )));
                    winrt::Windows::UI::Xaml::VisualStateManager::GoToState(container, L"EmptyBehaviorState", true);
                    winrt::Windows::UI::Xaml::VisualStateManager::GoToState(container, LoopingVisualStateName, true);
                    control->updateAnimation(true);
                    return;
                }
            }
        }

    }

    void MarqueeContainer::resumeStoryboardImpl()
    {
        if (!isHovering && !isPausing)
            marqueeStoryboard.Resume();
    }

    void MarqueeContainer::container_SizeChanged(winrt::Windows::Foundation::IInspectable sender, winrt::Windows::UI::Xaml::SizeChangedEventArgs const& e)
    {
        if (!marqueeContainer)
            return;

        //TODO: set clip in xaml?
        winrt::Windows::UI::Xaml::Media::RectangleGeometry rect;
        rect.Rect({ 0, 0, e.NewSize().Width, e.NewSize().Height });
        marqueeContainer.Clip(rect);
        startMarquee();
    }

    constexpr std::wstring_view MarqueeContainer::getVisualStateName(MarqueeDirection direction)
    {
        switch (direction)
        {
        case winrt::UWPExample::MarqueeDirection::Left: return LeftwardsVisualStateName;
        case winrt::UWPExample::MarqueeDirection::Right: return RightwardsVisualStateName;
        case winrt::UWPExample::MarqueeDirection::Up: return UpwardsVisualStateName;
        case winrt::UWPExample::MarqueeDirection::Down: return DownwardsVisualStateName;
        }
    }

    constexpr std::wstring_view MarqueeContainer::getVisualStateName(MarqueeBehavior behavior)
    {
        switch (behavior)
        {
        case winrt::UWPExample::MarqueeBehavior::Ticker: return TickerVisualStateName;
        case winrt::UWPExample::MarqueeBehavior::Looping: return LoopingVisualStateName;
        case winrt::UWPExample::MarqueeBehavior::Bouncing: return BouncingVisualStateName;
        }
    }

    void MarqueeContainer::startMarquee()
    {
        bool const initial = std::exchange(isActive, true);
        bool const playing = updateAnimation(initial);
        if (playing && !initial)
        {
            // Invoke MarqueeBegan if Marquee is now playing and was not before
            marqueeBegan();
        }
    }

    void MarqueeContainer::stopMarquee(bool initialState)
    {
        isActive = false;
        bool const playing = updateAnimation(false);
        if (!playing && initialState)
        {
            // Invoke MarqueeStopped if Marquee is not playing and was before
            marqueeStopped();
        }
    }

    bool MarqueeContainer::updateAnimation(bool resume)
    {
        if (!marqueeContainer ||
            !marqueeTransform ||
            !segment1 ||
            !segment2)
            return false;

        if (!isActive)
        {
            winrt::Windows::UI::Xaml::VisualStateManager::GoToState(*this, MarqueeStoppedState, false);
            return false;
        }

        double containerSize{};
        double segmentSize{};
        double value{};
        std::wstring_view targetProperty;

        MarqueeDirection const direction = Direction();
        if (isHorizontal(direction))
        {
            containerSize = marqueeContainer.ActualWidth();
            segmentSize = segment1.ActualWidth();
            value = marqueeTransform.X();
            targetProperty = L"(TranslateTransform.X)";
        }
        else
        {
            //vertical direction
            containerSize = marqueeContainer.ActualHeight();
            segmentSize = segment1.ActualHeight();
            value = marqueeTransform.Y();
            targetProperty = L"(TranslateTransform.Y)";
        }

        MarqueeBehavior const behavior = Behavior();
        if (behavior == MarqueeBehavior::Looping && segmentSize < containerSize)
        {
            stopMarquee(resume);
            segment2.Visibility(winrt::Windows::UI::Xaml::Visibility::Collapsed);
            return false;
        }

/*
            Initially:
                                            container size
                                        |--------------------|
                                        some loooooooooooooooong marqueeing text
-----------------------------------------------------------------------------------------------------
            TickerMode:
                start:
                                            container size
                                        |--------------------|
                                                             some loooooooooooooooong marqueeing text	
                end:
                                            container size
                                        |--------------------|
some loooooooooooooooong marqueeing text

------------------------------------------------------------------------------------------------------
            BouncingMode:
                start:
                                            container size
                                        |--------------------|
                                        some loooooooooooooooong marqueeing text
                end:
                                            container size
                                        |--------------------|
                      some loooooooooooooooong marqueeing text
------------------------------------------------------------------------------------------------------

*/
        double start = behavior == MarqueeBehavior::Ticker ? containerSize : 0;
        double end = behavior == MarqueeBehavior::Bouncing ? -(segmentSize - containerSize) : -segmentSize;
        double const distance = std::abs(start - end);
        
        if (distance == 0) return false;
        if (direction == MarqueeDirection::Right || direction == MarqueeDirection::Down)
        {
            std::swap(start, end);
        }

        segment2.Visibility(behavior == MarqueeBehavior::Looping ? winrt::Windows::UI::Xaml::Visibility::Visible : winrt::Windows::UI::Xaml::Visibility::Collapsed);

        if (marqueeStoryboard)
        {
            marqueeStoryboard.Completed(storyboardComplete_revoker);
        }

        std::chrono::milliseconds const duration{ static_cast<int64_t>(distance / Speed() * 1000.0) };
        marqueeStoryboard = createStoryboard(
            start,
            end,
            duration,
            targetProperty
        );
        storyboardComplete_revoker = marqueeStoryboard.Completed({ this, &MarqueeContainer::storyboard_completed });
        winrt::Windows::UI::Xaml::VisualStateManager::GoToState(*this, MarqueeActiveState, true);
        marqueeStoryboard.Begin();
        if (resume)
        {
            double const progress = std::abs(start - value) / distance;
            //marqueeStoryboard.Seek(winrt::Windows::Foundation::TimeSpan{ static_cast<int64_t>(duration.count() * progress * 10000) });
            auto const seekPosition = duration * progress;
            marqueeStoryboard.Seek(std::chrono::duration_cast<winrt::Windows::Foundation::TimeSpan>(seekPosition));
        }
        return true;
    }

    winrt::Windows::UI::Xaml::Media::Animation::Storyboard MarqueeContainer::createStoryboard(
        double start, 
        double end, 
        winrt::Windows::Foundation::TimeSpan duration, 
        std::wstring_view targetProperty)
    {
        winrt::Windows::UI::Xaml::Media::Animation::Storyboard storyboard;
        winrt::Windows::UI::Xaml::Media::Animation::DoubleAnimationUsingKeyFrames animation;
        winrt::Windows::UI::Xaml::Duration const d = winrt::Windows::UI::Xaml::DurationHelper::FromTimeSpan(duration);
        animation.Duration(d);
        animation.RepeatBehavior(RepeatBehavior());
        animation.AutoReverse(Behavior() == MarqueeBehavior::Bouncing);
        winrt::Windows::UI::Xaml::Media::Animation::LinearDoubleKeyFrame frame[2];
        frame[0].Value(start);
        frame[1].Value(end);
        frame[1].KeyTime({ duration });
        animation.KeyFrames().Append(frame[0]);
        animation.KeyFrames().Append(frame[1]);
        storyboard.Children().Append(animation);
        storyboard.Duration(d);
        storyboard.RepeatBehavior(RepeatBehavior());

        winrt::Windows::UI::Xaml::Media::Animation::Storyboard::SetTarget(animation, marqueeTransform);
        winrt::Windows::UI::Xaml::Media::Animation::Storyboard::SetTargetProperty(animation, targetProperty);
        return storyboard;
    }

    void MarqueeContainer::storyboard_completed(
        winrt::Windows::Foundation::IInspectable sender, 
        winrt::Windows::Foundation::IInspectable e)
    {
        stopMarquee(true);
        marqueeCompleted();
    }

    bool MarqueeContainer::isHorizontal(MarqueeDirection direction)
    {
        return direction == MarqueeDirection::Left || direction == MarqueeDirection::Right;
    }
}
