﻿#include "pch.h"
#include "IsNullOrEmptyStateTrigger.h"
#if __has_include("IsNullOrEmptyStateTrigger.g.cpp")
#include "IsNullOrEmptyStateTrigger.g.cpp"
#endif
#include <winrt/Microsoft.UI.Xaml.Interop.h>

namespace winrt::WinUI3Package::implementation
{
	IsNullOrEmptyStateTrigger::IsNullOrEmptyStateTrigger()
	{
		updateTrigger();
	}

	winrt::Microsoft::UI::Xaml::DependencyProperty IsNullOrEmptyStateTrigger::m_valueProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"Value",
			winrt::xaml_typename<winrt::Windows::Foundation::IInspectable>(),
			winrt::xaml_typename<WinUI3Package::IsNullOrEmptyStateTrigger>(),
			winrt::Microsoft::UI::Xaml::PropertyMetadata{
				nullptr,
				&IsNullOrEmptyStateTrigger::onValuePropertyChanged
			}
	);

	winrt::Windows::Foundation::IInspectable IsNullOrEmptyStateTrigger::Value()
	{
		return GetValue(m_valueProperty);
	}

	void IsNullOrEmptyStateTrigger::Value(winrt::Windows::Foundation::IInspectable value)
	{
		SetValue(m_valueProperty, value);
	}

	winrt::Microsoft::UI::Xaml::DependencyProperty IsNullOrEmptyStateTrigger::ValueProperty()
	{
		return m_valueProperty;
	}

	void IsNullOrEmptyStateTrigger::onValuePropertyChanged(winrt::Microsoft::UI::Xaml::DependencyObject d, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const e)
	{
		winrt::get_self<IsNullOrEmptyStateTrigger>(d.as<WinUI3Package::IsNullOrEmptyStateTrigger>())->updateTrigger();
	}

	void IsNullOrEmptyStateTrigger::updateTrigger()
	{
		auto val = Value();
		SetActive(isNullOrEmpty(val));

		if (!val)
			return;

		if (auto valNotifyCollection = val.try_as<winrt::Microsoft::UI::Xaml::Interop::INotifyCollectionChanged>())
		{
			valNotifyCollection.CollectionChanged([weakThis = get_weak()](auto sender, auto)
				{
					if (auto strongThis = weakThis.get())
						strongThis->SetActive(isNullOrEmpty(sender));
				});
			return;
		}

		if (auto valObservableVector = val.try_as<winrt::Windows::Foundation::Collections::IObservableVector<winrt::Windows::Foundation::IInspectable>>())
		{
			valObservableVector.VectorChanged([weakThis = get_weak()](auto sender, auto)
				{
					if (auto strongThis = weakThis.get())
						strongThis->SetActive(isNullOrEmpty(sender));
				});
			return;
		}

		if (auto valObservableMap = val.try_as<winrt::Windows::Foundation::Collections::IObservableMap<winrt::Windows::Foundation::IInspectable, winrt::Windows::Foundation::IInspectable>>())
		{
			valObservableMap.MapChanged([weakThis = get_weak()](auto sender, auto)
				{
					if (auto strongThis = weakThis.get())
						strongThis->SetActive(isNullOrEmpty(sender));
				});
		}
	}

	bool IsNullOrEmptyStateTrigger::isNullOrEmpty(winrt::Windows::Foundation::IInspectable val)
	{
		if (!val)
			return true;

		if (auto valString = val.try_as<winrt::hstring>())
		{
			return valString->empty();
		}

		if (auto valCollection = val.try_as<winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Foundation::IInspectable>>())
			return valCollection.Size() == 0;

		if (auto valEnumerable = val.try_as<winrt::Windows::Foundation::Collections::IIterable<winrt::Windows::Foundation::IInspectable>>())
		{
			for (auto item : valEnumerable)
				return false;
			return true;
		}

		return false;
	}
}
