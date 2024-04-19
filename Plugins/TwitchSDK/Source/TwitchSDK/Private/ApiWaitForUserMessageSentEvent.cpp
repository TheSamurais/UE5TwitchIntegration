// Fill out your copyright notice in the Description page of Project Settings.


#include "ApiWaitForUserMessageSentEvent.h"

void UApiWaitForUserMessageSentEvent::Activate() {
    TWeakObjectPtr<UApiWaitForUserMessageSentEvent> weak(this);
    auto exception_handler = [weak](const std::exception& e) {
        if (weak.IsValid() && weak->Error.IsBound())
            weak->Error.Broadcast(FTwitchSDKUserMessageSentEvent(), FString(e.what()));
        else
            UE_LOG(LogTwitchSDK, Error, TEXT("WaitForUserMessageSentEvent error: %s"), UTF8_TO_TCHAR(e.what()));
        };
    auto v = Desc;
    try {
        FTwitchSDKModule::Get().Core->WaitForUserMessageSentEvent(
            v,
            [weak](const R66::UserMessageSentEvent& r) {
                if (!weak.IsValid()) return;
                FTwitchSDKUserMessageSentEvent v(r);
                weak->Done.Broadcast(v, FString());
            },
            exception_handler
        );
    }
    catch (const std::exception& e) {
        exception_handler(e);
    }
}

UApiWaitForUserMessageSentEvent* UApiWaitForUserMessageSentEvent::WaitForUserMessageSentEvent(FTwitchSDKEventStreamDesc desc) {
    auto ptr = NewObject<UApiWaitForUserMessageSentEvent>();
    ptr->Desc = desc;
    return ptr;
}