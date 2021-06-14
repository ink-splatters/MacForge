//
//  MECore.h
//  Dark Boot
//
//  Created by Wolfgang Baird on 5/8/20.
//

@import AppKit;
@import CocoaMarkdown;
@import AppCenterAnalytics;

void SafeRelease(CFTypeRef cf);

@interface MF_FlippedView : NSView
@end

@interface MECoreSBButton : NSView

@property Boolean                   selected;
@property IBOutlet NSImageView*     buttonImage;
@property IBOutlet NSButton*        buttonClickArea;
@property IBOutlet NSButton*        buttonExtra;
@property IBOutlet NSView*          buttonHighlightArea;
@property IBOutlet NSTextField*     buttonLabel;
@property IBOutlet NSView*          linkedView;

@end

@interface MECore: NSObject

@property NSUInteger                macOS;
@property IBOutlet NSArray          *preferenceViews;
@property IBOutlet NSToolbarItem    *prefToolbar;
@property IBOutlet NSArray          *sidebarTopButtons;
@property IBOutlet NSArray          *sidebarBotButtons;
@property IBOutlet NSView           *mainView;
@property IBOutlet NSWindow         *mainWindow;
@property IBOutlet NSWindow         *prefWindow;
@property IBOutlet NSTextView       *changeLog;

+ (MECore*)sharedInstance;                      // Share
+ (NSUInteger)macOS;                            // macOS major version as integer counting anything beyond 10.X as major + 5
+ (NSColor*)blackOrWhite;                       // Black when system is light, white when system is dark
+ (void)whatsNew;                               // Show what's new popup if not yet shown for current version
+ (BOOL)hasLoggedCurrentVersion;
+ (void)logInfo:(BOOL)activated;                // Log some basic info
+ (void)rediecrLogToFolder:(NSString*)folder;   // Direct all logging to ~/Library/ApplicationSupport/(folder)/(executablename).log
- (void)setupSidebar;
- (IBAction)selectView:(id)sender;
- (IBAction)selectPreference:(id)sender;
- (IBAction)selectAboutInfo:(id)sender;
- (void)setMainViewSubView:(NSView*)subview;
- (void)setViewSubViewWithScrollableView:(NSView*)view :(NSView*)subview ;
- (void)systemDarkModeChange:(NSNotification *)notif;

@end
