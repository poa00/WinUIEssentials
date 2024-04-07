#pragma once
#include <string_view>
#include <winrt/Windows.Foundation.h>
#include <format>
#include <vector>
#include <boost/algorithm/string.hpp>

namespace BuiltInUris
{
    struct UriBase : private std::wstring_view
    {
        constexpr UriBase(std::wstring_view uri) : std::wstring_view{ uri }{}
        operator winrt::Windows::Foundation::Uri() const { return winrt::Windows::Foundation::Uri{ static_cast<std::wstring_view const&>(*this) }; }
    };


    //https://learn.microsoft.com/en-us/windows/uwp/launch-resume/launch-settings-app
    namespace Settings
    {
        #pragma region Accounts
        struct Workplace : public UriBase
        {
            constexpr static inline UriBase Provisioning{ L"ms-settings:workplace-provisioning" };
            constexpr static inline UriBase RepairToken{ L"ms-settings:workplace-repairtoken" };
            constexpr Workplace(std::wstring_view uri) : UriBase{ uri } { }
        }Workplace{ L"ms-settings:workplace" };
        constexpr UriBase EmailAndAccounts{ L"ms-settings:emailandaccounts" };
        constexpr UriBase OtherUsers{ L"ms-settings:otherusers" };
        constexpr UriBase AssignedAccess{ L"ms-settings:assignedaccess" };
        struct SignInOptions : public UriBase
        {
            constexpr static inline UriBase DynamicLock{ L"ms-settings:signinoptions-dynamic-lock" };
            constexpr static inline UriBase LaunchFaceEnrollment{ L"ms-settings:signinoptions-launchfaceencrollment" };
            constexpr static inline UriBase LaunchFingerprintEnrollment{ L"ms-settings:signinoptions-launchfingerprintenrollment" };
            constexpr static inline UriBase LanchSecurityKeyEnrollment{ L"ms-settings:signinoptions-launchsecuritykeyenrollment" };
            constexpr SignInOptions(std::wstring_view uri) : UriBase{ uri } {}
        }SignInOptions{ L"ms-settings:signinoptions" };
        constexpr UriBase Sync{ L"ms-settings:sync" };
        constexpr UriBase YourInfo{ L"ms-settings:yourinfo" };
        #pragma endregion

        #pragma region Apps
        struct DefaultApps : winrt::Windows::Foundation::Uri
        {
            struct RegisteredAppUser : std::wstring_view
            {
                using BaseType = std::wstring_view;
                constexpr RegisteredAppUser(std::wstring_view name) : std::wstring_view{ name }{}
            };
            struct RegisteredAppMachine : std::wstring_view
            {
                using BaseType = std::wstring_view;
                constexpr RegisteredAppMachine(std::wstring_view name) : std::wstring_view{ name }{}
            };
            struct RegisteredAUMID : std::wstring_view
            {
                using BaseType = std::wstring_view;
                constexpr RegisteredAUMID(std::wstring_view applicationUserModelId) : std::wstring_view{ applicationUserModelId }{}
            };

            DefaultApps(RegisteredAppUser registeredAppUser) :
                Uri{ std::format(L"ms-settings:defaultapps?registeredAppUser={}", winrt::Windows::Foundation::Uri::EscapeComponent(registeredAppUser)) }
            {
            }
            DefaultApps(RegisteredAppMachine registeredAppMachine) :
                Uri{ std::format(L"ms-settings:defaultapps?registeredAppMachine={}", winrt::Windows::Foundation::Uri::EscapeComponent(registeredAppMachine)) }
            {
            }
            DefaultApps(RegisteredAUMID registeredAUMID) :
                Uri{ std::format(L"ms-settings:defaultapps?registeredAUMID={}", static_cast<RegisteredAUMID::BaseType&>(registeredAUMID)) }
            {
            }
        };
        constexpr UriBase DefaultApps{ L"ms-settings:defaultapps" };
        constexpr UriBase AppsFeatures{ L"ms-settings:appsfeatures" };
        constexpr UriBase AppsFeaturesApp{ L"ms-settings:appsfeatures-app" };
        constexpr UriBase AppsForWebsites{ L"ms-settings:appsforwebsites" };
        constexpr UriBase DefaultBrowserSettings{ L"ms-settings:defaultbrowsersettings" };
        constexpr UriBase OptionalFeatures{ L"ms-settings:optionalfeatures" };
        struct Maps : UriBase
        {
            constexpr static inline UriBase DownloadMaps{ L"ms-settings:maps-downloadmaps" };
            constexpr Maps(std::wstring_view uri) : UriBase{ uri } {}
        } Maps{ L"ms-settings:maps" };
        constexpr UriBase StartupApps{ L"ms-settints:startupapps" };
        constexpr UriBase VideoPlayback{ L"ms-setttings:videoplayback" };
        #pragma endregion

        #pragma region ControlCenter
        constexpr UriBase ControlCenter{ L"ms-settings:controlcenter" };
        #pragma endregion

        #pragma region Cortana
        struct Cortana : UriBase
        {
            constexpr static inline UriBase CortanaNotifications{ L"ms-settings:cortana-notifications" };
            constexpr static inline UriBase CortanaMoreDetails{ L"ms-settings:cortana-moredetails" };
            constexpr static inline UriBase CortanaPermissions{ L"ms-settings:cortana-permissions" };
            constexpr static inline UriBase CortanaWindowsSearch{ L"ms-settings:cortana-windowssearch" };
            constexpr static inline UriBase CortanaLanguage{ L"ms-settings:cortana-language" };
            constexpr static inline UriBase CortanaTalkToCortana{ L"ms-settings:cortana-talktocortana" };
            constexpr Cortana(std::wstring_view uri) : UriBase{ uri } {}
        } Cortana{ L"ms-settings:cortana" };
        #pragma endregion

        #pragma region Devices
        constexpr UriBase Autoplay{ L"ms-settings:autoplay" };
        constexpr UriBase Bluetooth{ L"ms-settings:bluetooth" };
        constexpr UriBase ConnectedDevices{ L"ms-settings:connecteddevices" };
        constexpr UriBase Camera{ L"ms-settings:camera" };
        struct Camera : winrt::Windows::Foundation::Uri
        {
            Camera(std::wstring_view cameraId) : Uri{ std::format(L"ms-settings:camera?cameraId=", Uri::EscapeComponent(cameraId)) } {}
        };
        constexpr UriBase MouseTouchpad{ L"ms-settings:mousetouchpad" };
        constexpr UriBase Pen{ L"ms-settings:pen" };
        constexpr UriBase Printers{ L"ms-settings:printers" };
        namespace Devices
        {
            constexpr UriBase Touch{ L"ms-settings:devices-touch" };
            constexpr UriBase Touchpad{ L"ms-settings:devices-touchpad" };
        }
        constexpr UriBase DevicesTypingHwkbTextSuggestions{ L"ms-settings:devicestyping-hwkbtextsuggestions" };
        constexpr UriBase Typing{ L"ms-settings:typing" };
        constexpr UriBase USB{ L"ms-settings:usb" };
        constexpr UriBase Wheel{ L"ms-settings:wheel" };
        #pragma endregion

        #pragma region EaseOfAccess
        namespace EaseOfAccess
        {
            constexpr UriBase Audio{ L"ms-settings:easeofaccess-audio" };
            constexpr UriBase ClosedCaptioning{ L"ms-settings:easeofaccess-closedcaptioning" };
            constexpr UriBase ColorFilter{ L"ms-settings:easeofaccess-colorfilter" };
            constexpr UriBase ColorFilterAdaptiveColorLink{ L"ms-settings:easeofaccess-colorfilter-adaptivecolorlink" };
            constexpr UriBase ColorFilterBlueLightLink{ L"ms-settings:easeofaccess-colorfilter-bluelightlink" };
            constexpr UriBase Display{ L"ms-settings:easeofaccess-display" };
            constexpr UriBase EyeControl{ L"ms-settings:easeofaccess-eyecontrol" };
            constexpr UriBase HighContrast{ L"ms-settings:easeofaccess-highcontrast" };
            constexpr UriBase Keryboard{ L"ms-settings:easeofaccess-keyboard" };
            constexpr UriBase Magnifier{ L"ms-settings:easeofaccess-magnifier" };
            constexpr UriBase Mouse{ L"ms-settings:easeofaccess-mouse" };
            constexpr UriBase MousePionter{ L"ms-settings:easeofaccess-mousepointer" };
            constexpr UriBase Narrator{ L"ms-settings:easeofaccess-narrator" };
            constexpr UriBase NarratorIsAutoStartEnabled{ L"ms-settings:easeofaccess-isautostartenabled" };
            constexpr UriBase Speech{ L"ms-settings:easeofaccess-speechrecognition" };
            constexpr UriBase Cursor{ L"ms-settings:easeofaccess-cursor" };
            constexpr UriBase VisualEffects{ L"ms-settings:easeofaccess-visualeffects" };
        }
        constexpr UriBase Fonts{ L"ms-settings:fonts" };
        #pragma endregion

        #pragma region Extras
        constexpr UriBase Extras{ L"ms-settings:extras" };
        #pragma endregion

        #pragma region FamilyGroup
        constexpr UriBase FamilyGroup{ L"ms-settings:family-group" };
        #pragma endregion

        #pragma region Gaming
        namespace Gaming
        {
            constexpr UriBase GameBar{ L"ms-settings:gaming-gamebar" };
            constexpr UriBase GameDVR{ L"ms-settings:gaming-gamedvr" };
            constexpr UriBase TruePlay{ L"ms-settings:gaming-trueplay" };
        }
        constexpr UriBase GameMode{ L"ms-settings:gamemode" };
        constexpr UriBase QuietMomentsGame{ L"ms-settings:quietmomentsgame" };
        #pragma endregion

#pragma region MixedReality
        namespace Holographic
        {
            constexpr UriBase Audio{ L"ms-settings:holographic-audio" };
            constexpr UriBase Headset{ L"ms-settings:holographic-headset" };
            constexpr UriBase Management{ L"ms-settings:holographic-management" };
            constexpr UriBase StartupAndDesktop{ L"ms-settings:holographic-startupanddesktop" };
        }
#pragma endregion

#pragma region NetworkAndInternet
        namespace Network
        {
            constexpr UriBase Status{ L"ms-settings:network-status" };
            constexpr UriBase AdvancedSettings{ L"ms-settings:network-advancedsettings" };
            constexpr UriBase AirplaneMode{ L"ms-settings:network-airplanemode" };
            constexpr UriBase Cellular{ L"ms-settings:network-cellular" };
            constexpr UriBase DirectAccess{ L"ms-settings:network-directaccess" };
            constexpr UriBase Ethernet{ L"ms-settings:network-ethernet" };
            constexpr UriBase WifiSettings{ L"ms-settings:network-wifisettings" };
            constexpr UriBase MobileHotspot{ L"ms-settings:network-mobile-hotspot" };
            constexpr UriBase Proxy{ L"ms-settings:network-proxy" };
            constexpr UriBase VPN{ L"ms-settings:network-vpn" };
            constexpr UriBase Wifi{ L"ms-settings:network-wifi" };
        }
        constexpr UriBase Proximity{ L"ms-settings:proximity" };
        constexpr UriBase Dialup{ L"ms-settings:dialup" };
        namespace Wifi
        {
            constexpr UriBase Provisioning{ L"ms-settings:wifi-provisioning" };
        }
        #pragma endregion

        #pragma region Personlization
        struct Personalization : UriBase
        {
            constexpr static inline UriBase Background{ L"ms-settings:personalization-background" };
            constexpr static inline UriBase StartPlaces{ L"ms-settings:personalization-start-places" };
            constexpr static inline UriBase Colors{ L"ms-settings:personalization-colors" };
            constexpr static inline UriBase Glance{ L"ms-settings:personalization-glance" };
            constexpr static inline UriBase Start{ L"ms-settings:personalization-start" };
            constexpr static inline UriBase NavBar{ L"ms-settings:personlization-navbar" };
            constexpr static inline UriBase TouchKeyboard{ L"ms-settings:personalization-touchkeyboard" };
            constexpr Personalization(std::wstring_view uri) : UriBase{ uri } {}
        } Personalization{ L"ms-settings:personalization" };
        constexpr UriBase Colors{ L"ms-settings:colors" };
        constexpr UriBase Lockscreen{ L"ms-settings:lockscreen" };
        constexpr UriBase Themes{ L"ms-settings:themes" };
        #pragma endregion

        #pragma region Phone
        struct MobileDevices : public UriBase
        {
            struct AddPhone : public UriBase
            {
                constexpr static inline UriBase Direct{ L"ms-settings:mobile-devices-addphone-direct" };
                constexpr AddPhone(std::wstring_view uri) : UriBase{ uri } {}
            } AddPhone{ L"ms-settings:mobile-devices-addphone" };

            constexpr MobileDevices(std::wstring_view uri) : UriBase{ uri } {}
        } MobileDevices{ L"ms-settings:mobile-devices" };
        constexpr UriBase DeviceUsage{ L"ms-settings:deviceusage" };
        #pragma endregion

        #pragma region Privacy
        struct Privacy : public UriBase
        {
            constexpr static inline UriBase AccessoryApps{ L"ms-settings:privacy-accessoryapps" };
            constexpr static inline UriBase AccountInfo{ L"ms-settings:privacy-accountinfo" };
            constexpr static inline UriBase ActivityHistory{ L"ms-settings:privacy-activityhistory" };
            constexpr static inline UriBase AdvertisingId{ L"ms-settings:privacy-advertisingid" };
            constexpr static inline UriBase AppDiagnostics{ L"ms-settings:privacy-appdiagnostics" };
            constexpr static inline UriBase AutomaticFileDownloads{ L"ms-settings:privacy-automaticfiledownloads" };
            constexpr static inline UriBase BackgroundApps{ L"ms-settings:privacy-backgroundapps" };
            constexpr static inline UriBase BackgroundSpatialPerception{ L"ms-settings:privacy-backgroundspatialperception" };
            constexpr static inline UriBase Calender{ L"ms-settings:privacy-calendar" };
            constexpr static inline UriBase CallHistory{ L"ms-settings:privacy-callhistory" };
            constexpr static inline UriBase WebCam{ L"ms-settings:privacy-webcam" };
            constexpr static inline UriBase Contacts{ L"ms-settings:privacy-contacts" };
            constexpr static inline UriBase Documents{ L"ms-settings:privacy-documents" };
            constexpr static inline UriBase DownloadsFolder{ L"ms-settings:privacy-downloadsfolder" };
            constexpr static inline UriBase Email{ L"ms-settings:privacy-email" };
            constexpr static inline UriBase EyeTracker{ L"ms-settings:privacy-eyetracker" };
            constexpr static inline UriBase Feedback{ L"ms-settings:privacy-feedback" };
            constexpr static inline UriBase BroadFilesystemAccess{ L"ms-settings:privacy-broadfilesystemaccess" };
            constexpr static inline UriBase General{ L"ms-settings:privacy-general" };
            constexpr static inline UriBase GraphicsCaptureProgrammatic{ L"ms-settings:privacy-graphicscaptureprogrammatic" };
            constexpr static inline UriBase GraphicsCaptureWithoutBorder{ L"ms-settings:privacy-graphicscapturewithoutborder" };
            constexpr static inline UriBase SpeechTyping{ L"ms-settings:privacy-speechtyping" };
            constexpr static inline UriBase Location{ L"ms-settings:privacy-location" };
            constexpr static inline UriBase Messaging{ L"ms-settings:privacy-messaging" };
            constexpr static inline UriBase Microphone{ L"ms-settings:privacy-microphone" };
            constexpr static inline UriBase Motion{ L"ms-settings:privacy-motion" };
            constexpr static inline UriBase MusicLibrary{ L"ms-settings:privacy-musiclibrary" };
            constexpr static inline UriBase Notifications{ L"ms-settings:privacy-notifications" };
            constexpr static inline UriBase CustomDevices{ L"ms-settings:privacy-customdevices" };
            constexpr static inline UriBase PhoneCalls{ L"ms-settings:privacy-phonecalls" };
            constexpr static inline UriBase Pictures{ L"ms-settings:privacy-pictures" };
            constexpr static inline UriBase Radios{ L"ms-settings:privacy-radios" };
            constexpr static inline UriBase Speech{ L"ms-settings:privacy-speech" };
            constexpr static inline UriBase Tasks{ L"ms-settings:privacy-tasks" };
            constexpr static inline UriBase Videos{ L"ms-settings:privacy-videos" };
            constexpr static inline UriBase VoiceActivation{ L"ms-settings:privacy-voiceactivation" };
            constexpr static inline UriBase HolographicEnvironment{ L"ms-settings:privacy-holographic-environment" };
            constexpr Privacy(std::wstring_view uri) : UriBase{ uri } {}
        } Privacy{ L"ms-settings:privacy" };
        #pragma endregion

        #pragma region Search
        struct Search : public UriBase
        {
            constexpr static inline UriBase MoreDetails{ L"ms-settings:search-moredetails" };
            constexpr static inline UriBase Permissions{ L"ms-settings:permissions" };
            constexpr Search(std::wstring_view uri) : UriBase{ uri } {}
        } Search{ L"ms-settings:search" };
        #pragma endregion

        #pragma region SurfaceHub
        namespace SurfaceHub
        {
            constexpr static inline UriBase Accounts{ L"ms-settings:surfacehub-accounts" };
            constexpr static inline UriBase SessionCleanup{ L"ms-settings:surfacehub-sessioncleanup" };
            constexpr static inline UriBase Calling{ L"ms-settings:surfacehub-calling" };
            constexpr static inline UriBase DeviceManagement{ L"ms-settings:surfacehub-devicemanagement" };
            constexpr static inline UriBase Welcome{ L"ms-settings:surfacehub-welcome" };
        }
        #pragma endregion

        #pragma region System
        constexpr UriBase About{ L"ms-settings:about" };
        struct Display : public UriBase
        {
            constexpr static inline UriBase Advanced{ L"ms-settings:display-advanced" };
            struct AdvancedGraphics : public UriBase
            {
                constexpr static inline UriBase Default{ L"ms-settings:display-advancedgraphics-default" };
                constexpr AdvancedGraphics(std::wstring_view uri) : UriBase{ uri } {}
            } AdvancedGraphics{ L"ms-settings:display-advancedgraphics" };
            constexpr Display(std::wstring_view uri) : UriBase{ uri } {}
        } Display{ L"ms-settings:display" };
        namespace Apps
        {
            constexpr UriBase Volume{ L"ms-settings:apps-volume" };
        }
        struct BatterySaver : public UriBase
        {
            constexpr static inline UriBase Settings{ L"ms-settings:batterysaver-settings" };
            constexpr static inline UriBase UsageDetails{ L"ms-settings:batterysaver-usagedetails" };
            constexpr BatterySaver(std::wstring_view uri) : UriBase{ uri } {}
        } BatterySaver{ L"ms-settings:batterysaver" };
        constexpr UriBase Clipboard{ L"ms-settings:clipboard" };
        constexpr UriBase SaveLocations{ L"ms-settings:savelocations" };
        constexpr UriBase ScreenRotation{ L"ms-settings:screenrotation" };
        constexpr UriBase QuietMomentsPresentation{ L"ms-settings:quietmomentspresentation" };
        constexpr UriBase QuietMomentsScheduled{ L"ms-settings:quietmomentsscheduled" };
        constexpr UriBase DeviceEncryption{ L"ms-settings:deviceencryption" };
        constexpr UriBase EnergyRecommendations{ L"ms-settings:energyrecommendations" };
        constexpr UriBase QuietHours{ L"ms-settings:quiethours" };
        struct MultiTasking : public UriBase
        {
            constexpr static inline UriBase SgUpdate{ L"ms-settings:multitasking-sgupdate" };
            constexpr MultiTasking(std::wstring_view uri) : UriBase{ uri } {}
        } MultiTasking{ L"ms-settings:multitasking" };
        constexpr UriBase NightLight{ L"ms-settings:nightlight" };
        constexpr UriBase Project{ L"ms-settings:project" };
        constexpr UriBase CrossDevice{ L"ms-settings:crossdevice" };
        constexpr UriBase TabletMode{ L"ms-settings:tabletmode" };
        constexpr UriBase Taskbar{ L"ms-settings:taskbar" };
        constexpr UriBase Notifications{ L"ms-settings:notifications" };
        constexpr UriBase RemoteDesktop{ L"ms-settings:remotedesktop" };
        constexpr UriBase Phone{ L"ms-settings:phone" };
        constexpr UriBase PowerSleep{ L"ms-settings:powersleep" };
        constexpr UriBase Presence{ L"ms-settings:presence" };
        struct Sound : public UriBase
        {
            constexpr static inline UriBase Devices{ L"ms-settings:sound-devices" };
            constexpr Sound(std::wstring_view uri) : UriBase{ uri } {}
        } Sound{ L"ms-settings:sound" };
        constexpr UriBase Storage{ L"ms-settings:storage" };
        constexpr UriBase StoragePolicies{ L"ms-settings:storagepolicies" };
        constexpr UriBase StorageRecommendations{ L"ms-settings:storagerecommendations" };
        constexpr UriBase DisksAndVolumes{ L"ms-settings:diskandvolumes" };
        #pragma endregion

        #pragma region TimeAndLanguage
        constexpr UriBase DateAndTime{ L"ms-settings:dateandtime" };
        constexpr UriBase RegionFormatting{ L"ms-settings:regionformatting" };
        struct Keyboard : public UriBase
        {
            constexpr static inline UriBase Advanced{ L"ms-settings:keyboard-advanced" };
            constexpr Keyboard(std::wstring_view uri) : UriBase{ uri } {}
        } Keyboard{ L"ms-settings:keyboard" };
        struct RegionLanguage : public UriBase
        {
            constexpr static inline UriBase JpnIME{ L"ms-settings:regionlanguage-jpnime" };
            constexpr static inline UriBase BpmfIME{ L"ms-settings:regionlanguage-bpmfime" };
            constexpr static inline UriBase CangjieIME{ L"ms-settings:regionlanguage-cangjieime" };
            struct ChsIME
            {
                constexpr static inline UriBase WubiUdp{ L"ms-settings:regionlanguage-chsime-wubi-udp" };

                struct Pinyin : public UriBase
                {
                    constexpr static inline UriBase DomainLexicon{ L"ms-settings:regionlanguage-chsime-pinyin-domainlexicon" };
                    constexpr static inline UriBase KeyConfig{ L"ms-settings:regionlanguage-chsime-pinyin-keyconfig" };
                    constexpr static inline UriBase Udp{ L"ms-settings:regionlanguage-chsime-pinyin-udp" };
                    constexpr Pinyin(std::wstring_view uri) : UriBase{ uri } {}
                } Pinyin{ L"ms-settings:regionlanguage-chsime-pinyin" };
                constexpr static inline UriBase Wubi{ L"ms-settings:regionlanguage-chsime-wubi" };
            };

            constexpr static inline UriBase QuickIME{ L"ms-settings:regionlanguage-quickime" };
            constexpr static inline UriBase KorIME{ L"ms-settings:regionlanguage-korime" };
            constexpr static inline UriBase AddDisplayLanguage{ L"ms-settings:regionlanguage-adddisplaylanguage" };
            constexpr static inline UriBase LanguageOptions{ L"ms-settings:regionlangauge-languageoptions" };
            constexpr static inline UriBase SetDisplayLangauge{ L"ms-settings:regionlanguage-setdisplaylanguage" };
            constexpr RegionLanguage(std::wstring_view uri) : UriBase{ uri } {}
        } RegionLanguage{ L"ms-settings:regionlanguage" };
        #pragma endregion

        #pragma region UpdateAndSecurity
        constexpr UriBase Activation{ L"ms-settings:activation" };
        constexpr UriBase Backup{ L"ms-settings:backup" };
        struct DeliveryOptimization : public UriBase
        {
            constexpr static inline UriBase Activity{ L"ms-settings:delivery-optimization-activity" };
            constexpr static inline UriBase Advanced{ L"ms-settings:delivery-optimization-advanced" };
            constexpr DeliveryOptimization(std::wstring_view uri) : UriBase{ uri } {}
        } DeliveryOptimization{ L"ms-settings:delivery-optimization" };
        constexpr UriBase FindMyDevice{ L"ms-settings:findmydevice" };
        constexpr UriBase Developers{ L"ms-settings:developers" };
        constexpr UriBase Recovery{ L"ms-settings:recovery" };
        constexpr UriBase Troubleshoot{ L"ms-settings:troubleshoot" };
        constexpr UriBase WindowsDefender{ L"ms-settings:windowsdefender" };
        struct WindowsInsider : public UriBase
        {
            constexpr static inline UriBase Optin{ L"ms-settings:windowsinsider-optin" };
            constexpr WindowsInsider(std::wstring_view uri) : UriBase{ uri } {}
        } WindowsInsider{ L"ms-settings:windowsinsider" };
        struct WindowsUpdate : public UriBase
        {
            constexpr static inline UriBase Action{ L"ms-settings:windowsupdate-action" };
            constexpr static inline UriBase ActiveHours{ L"ms-settings:windowsupdate-activehours" };
            constexpr static inline UriBase Options{ L"ms-settings:windowsupdate-options" };
            constexpr static inline UriBase OptionalUpdates{ L"ms-settings:windowsupdate-optionalupdates" };
            constexpr static inline UriBase RestartOptions{ L"ms-settings:windowsupdate-restartoptions" };
            constexpr static inline UriBase SeekerOnDemand{ L"ms-settings:windowsupdate-seekderondemand" };
            constexpr static inline UriBase History{ L"ms-settings:windowsupdate-history" };
            constexpr WindowsUpdate(std::wstring_view uri) : UriBase{ uri } {}
        } WindowsUpdate{ L"ms-settings:windowsupdate" };
        #pragma endregion

        #pragma region UserAccount
        constexpr UriBase Provisioning{ L"ms-settings:provisioning" };
        constexpr UriBase WindowsAnywhere{ L"ms-settings:windowsanywhere" };
        #pragma endregion
    }

    namespace Store
    {
        constexpr UriBase Home{ L"ms-windows-store://home" };
        namespace NavigateToPage
        {
            constexpr UriBase Home{ L"ms-windows-store://navigatetopage/?Id=Home" };
            constexpr UriBase Gaming{ L"ms-windows-store://navigatetopage/?Id=Gaming" };
            constexpr UriBase Entertainment{ L"ms-windows-store://navigatetopage/?Id=entertainment" };
            constexpr UriBase Productivity{ L"ms-windows-store://navigatetopage/?Id=productivity" };
            constexpr UriBase LOB{ L"ms-windows-store://navigatetopage/?Id=lob" };
        }
        constexpr UriBase DownloadsAndUpdates{ L"ms-windows-store://downloadsandupdates" };
        constexpr UriBase Settings{ L"ms-windows-store://settings" };
        struct ProductId : std::wstring_view
        {
            using BaseType = std::wstring_view;
            explicit constexpr ProductId(std::wstring_view id) : std::wstring_view{ id }{}
        };
        struct PFN : std::wstring_view
        {
            using BaseType = std::wstring_view;
            explicit constexpr PFN(std::wstring_view packageFamilyName) : std::wstring_view{ packageFamilyName }{}
        };
        struct AppId : std::wstring_view
        {
            using BaseType = std::wstring_view;
            explicit constexpr AppId(std::wstring_view appId) : std::wstring_view{ appId }{}
        };
        struct ProductPage : public winrt::Windows::Foundation::Uri
        {
            ProductPage(std::wstring_view productId, bool mini = false) : Uri{ mini ?
                std::format(L"ms-windows-store://pdp/?ProductId={}&mode=mini", productId) :
                std::format(L"ms-windows-store://pdp/?ProductId={}", productId)
            }
            {}

            ProductPage(ProductId productId, bool mini = false) : Uri{ mini ?
                std::format(L"ms-windows-store://pdp/?ProductId={}&mode=mini", static_cast<ProductId::BaseType&>(productId)) :
                std::format(L"ms-windows-store://pdp/?ProductId={}", static_cast<ProductId::BaseType&>(productId))
            }
            {}

            ProductPage(AppId id, bool mini = false) : Uri{ mini ?
                std::format(LR"(ms-windows-store://pdp/?AppId={}&mode=mini)", static_cast<AppId::BaseType&>(id)) :
                std::format(LR"(ms-windows-store://pdp/?AppId={})", static_cast<AppId::BaseType&>(id))
            }
            {}

            ProductPage(PFN id, bool mini = false) : Uri{ mini ?
                std::format(LR"(ms-windows-store://pdp/?PFN={}&mode=mini)", static_cast<PFN::BaseType&>(id)) :
                std::format(LR"(ms-windows-store://pdp/?PFN={})", static_cast<PFN::BaseType&>(id))
            }
            {}
        };
        struct Review : public winrt::Windows::Foundation::Uri
        {
            Review(std::wstring_view productId) : Uri{ std::format(L"ms-windows-store://review/?ProductId={}", productId) } {}

            Review(ProductId productId) :
                Uri{ std::format(L"ms-windows-store://review/?ProductId={}", static_cast<ProductId::BaseType&>(productId)) }
            {}
            Review(AppId id) :
                Uri{ std::format(L"ms-windows-store://review/?AppId={}", static_cast<AppId::BaseType&>(id)) }
            {}
            Review(PFN id) :
                Uri{ std::format(L"ms-windows-store://review/?PFN={}", static_cast<PFN::BaseType&>(id)) }
            {}
        };
        struct Assoc : public winrt::Windows::Foundation::Uri
        {
            struct Tag : std::vector<std::wstring>
            {
                using BaseType = std::vector<std::wstring>;
                Tag(std::vector<std::wstring> tags) : std::vector<std::wstring>{ std::move(tags) } {}
            };
            struct FileExt : std::wstring_view
            {
                using BaseType = std::wstring_view;
                explicit constexpr FileExt(std::wstring_view fileExt) : std::wstring_view{ fileExt }{}
            };
            struct Protocol : std::wstring_view
            {
                using BaseType = std::wstring_view;
                explicit constexpr Protocol(std::wstring_view protocol) : std::wstring_view{ protocol }{}
            };


            Assoc(Tag tag) :
                Uri{ std::format(L"ms-windows-store://assoc/?Tags={}", boost::algorithm::join(static_cast<Tag::BaseType&>(tag), L",")) }
            {
            }
            Assoc(FileExt fileExt) : Uri{ std::format(L"ms-windows-store://assoc/?FileExt={}", static_cast<FileExt::BaseType&>(fileExt)) } {}
            Assoc(Protocol protocol) : Uri{ std::format(L"ms-windows-store://assoc/?Protocol={}", static_cast<Protocol::BaseType&>(protocol)) } {}
        };


        struct Search : public winrt::Windows::Foundation::Uri
        {
            Search(std::wstring_view query) : Uri{ std::format(L"ms-windows-store://search/?query={}", query) } {}
        };
        struct Publisher : public winrt::Windows::Foundation::Uri
        {
            Publisher(std::wstring_view name) : Uri{ std::format(L"ms-windows-store://publisher/?name={}", name) } {}
        };
    }
}