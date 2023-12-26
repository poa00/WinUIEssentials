#include "pch.h"
#include "WindowExPage.xaml.h"
#if __has_include("WindowExPage.g.cpp")
#include "WindowExPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::WinUI3Example::implementation
{
	void WindowExPage::Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		WinUI3Package::WindowEx window;
		if(auto extendContentIntoTitleBar = ExtendContentIntoTitleBarCheckBox().IsChecked()) 
			window.ExtendsContentIntoTitleBar(extendContentIntoTitleBar.GetBoolean());
		if(auto hasBorder = HasBorderCheckBox().IsChecked())
			window.HasBorder(hasBorder.GetBoolean());
		if(auto isResizable = IsResizableCheckBox().IsChecked())
			window.IsResizable(isResizable.GetBoolean());
		if(auto isMinimizable = IsMinimizableCheckBox().IsChecked())
			window.IsMinimizable(isMinimizable.GetBoolean());
		if(auto isMaximizable = IsMaximizableCheckBox().IsChecked())
			window.IsMaximizable(isMaximizable.GetBoolean());
		if (auto transparent = TransparentCheckBox().IsChecked(); transparent && transparent.GetBoolean())
		{
			window.SystemBackdrop(WinUI3Package::TransparentBackdrop{});
		}

		window.Activate();
	}
}
