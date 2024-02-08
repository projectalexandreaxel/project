#include "UMGHUDWidget.h"
#include "SlateHUDWidget.h"

TSharedRef<SWidget> UHUDWidget::RebuildWidget() {
    HUDWidget = SNew(SHUDWidget);

    return HUDWidget.ToSharedRef();
}

void UHUDWidget::ReleaseSlateResources(bool bReleaseChildren) {
    Super::ReleaseSlateResources(bReleaseChildren);

    HUDWidget.Reset();
}