#pragma once

#include "UriPage.g.h"
#include <BuiltInUris.hpp>

namespace winrt::UWPExample::implementation
{
    struct UriPage : UriPageT<UriPage>
    {
        UriPage() 
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Foundation::IInspectable> Uris()
        {
            using namespace BuiltInUris;

            return winrt::single_threaded_vector(std::vector<winrt::Windows::Foundation::IInspectable>
            {
                UWPExample::UriGroup{ L"Accounts", winrt::single_threaded_vector(std::vector<winrt::Windows::Foundation::IInspectable>
                {
                    UWPExample::UriModel{L"Access work or school", Settings::Workplace},
                    UWPExample::UriModel{L"Email & app accounts", Settings::EmailAndAccounts},
                    UWPExample::UriModel{L"Family & other people", Settings::OtherUsers},
                    UWPExample::UriModel{L"Set up a kiosk", Settings::AssignedAccess},
                    UWPExample::UriModel{L"Sign-in options", Settings::SignInOptions},
                    UWPExample::UriModel{L"Sign-in options", Settings::SignInOptions::DynamicLock},
                    UWPExample::UriModel{L"Sync your settings", Settings::Sync},
                    UWPExample::UriModel{L"Sync your settings", Settings::Backup},
                    UWPExample::UriModel{L"Windows Hello setup", Settings::SignInOptions::LaunchFaceEnrollment},
                    UWPExample::UriModel{L"Windows Hello setup", Settings::SignInOptions::LaunchFingerprintEnrollment},
                    UWPExample::UriModel{L"Your info", Settings::YourInfo}
                }) },
                UWPExample::UriGroup{L"Apps", winrt::single_threaded_vector(std::vector<winrt::Windows::Foundation::IInspectable>{
                    UWPExample::UriModel{L"Apps & Features", Settings::AppsFeatures},
                    UWPExample::UriModel{L"App features", Settings::AppsFeatures::App},
                    UWPExample::UriModel{L"Apps for websites", Settings::AppsForWebsites},
                    //default apps,
                    UWPExample::UriModel{L"Default browser settings", Settings::DefaultBrowserSettings},
                    UWPExample::UriModel{L"Manage optional features", Settings::OptionalFeatures},
                    UWPExample::UriModel{L"Offline Maps", Settings::Maps},
                    UWPExample::UriModel{L"Offline Maps", Settings::Maps::DownloadMaps},
                    UWPExample::UriModel{L"Startup apps", Settings::StartupApps},
                    UWPExample::UriModel{L"Video playback", Settings::VideoPlayback}
                })},
                UWPExample::UriGroup{ L"Control Center", winrt::single_threaded_vector(std::vector<winrt::Windows::Foundation::IInspectable>{
                    UWPExample::UriModel{L"Control center", Settings::ControlCenter}
                })}
            });
        }
    };
}

namespace winrt::UWPExample::factory_implementation
{
    struct UriPage : UriPageT<UriPage, implementation::UriPage>
    {
    };
}
