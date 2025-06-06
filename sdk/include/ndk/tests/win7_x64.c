/* Version definitions */
#undef NTDDI_VERSION
#define NTDDI_VERSION NTDDI_WIN7
#undef _WIN32_WINNT
#define _WIN32_WINNT _WIN32_WINNT_WIN7

#include <ntifs.h>
#include <ndk/ntndk.h>

#define C_ASSERT_FIELD(Type, Offset, MemberType, MemberName) \
    C_ASSERT(FIELD_OFFSET(Type, MemberName) == Offset); \
    C_ASSERT(FIELD_SIZE(Type, MemberName) == sizeof(MemberType));

/* KTHREAD */
C_ASSERT_FIELD(KTHREAD, 0x000, DISPATCHER_HEADER, Header)
C_ASSERT_FIELD(KTHREAD, 0x018, ULONG64, CycleTime)
C_ASSERT_FIELD(KTHREAD, 0x020, ULONG64, QuantumTarget)
C_ASSERT_FIELD(KTHREAD, 0x028, PVOID, InitialStack)
C_ASSERT_FIELD(KTHREAD, 0x030, PVOID, StackLimit)
C_ASSERT_FIELD(KTHREAD, 0x038, PVOID, KernelStack)
C_ASSERT_FIELD(KTHREAD, 0x040, ULONG64, ThreadLock)
C_ASSERT_FIELD(KTHREAD, 0x048, KWAIT_STATUS_REGISTER, WaitRegister)
C_ASSERT_FIELD(KTHREAD, 0x049, UCHAR, Running)
C_ASSERT_FIELD(KTHREAD, 0x04A, UCHAR[2], Alerted) // type is UCHAR[2]
C_ASSERT_FIELD(KTHREAD, 0x04C, LONG, MiscFlags)
C_ASSERT_FIELD(KTHREAD, 0x050, KAPC_STATE, ApcState)
//C_ASSERT_FIELD(KTHREAD, 0x050, UCHAR[23], ApcStateFill) // type is UCHAR[23]
C_ASSERT_FIELD(KTHREAD, 0x07B, CHAR, Priority)
C_ASSERT_FIELD(KTHREAD, 0x07C, ULONG, NextProcessor)
C_ASSERT_FIELD(KTHREAD, 0x080, ULONG, DeferredProcessor)
C_ASSERT_FIELD(KTHREAD, 0x088, ULONG64, ApcQueueLock)
C_ASSERT_FIELD(KTHREAD, 0x090, LONG64, WaitStatus)
C_ASSERT_FIELD(KTHREAD, 0x098, KWAIT_BLOCK*, WaitBlockList)
C_ASSERT_FIELD(KTHREAD, 0x0A0, LIST_ENTRY, WaitListEntry)
C_ASSERT_FIELD(KTHREAD, 0x0A0, SINGLE_LIST_ENTRY, SwapListEntry)
C_ASSERT_FIELD(KTHREAD, 0x0B0, PKQUEUE, Queue)
C_ASSERT_FIELD(KTHREAD, 0x0B8, PVOID, Teb)
C_ASSERT_FIELD(KTHREAD, 0x0C0, KTIMER, Timer)
C_ASSERT_FIELD(KTHREAD, 0x100, LONG, ThreadFlags)
C_ASSERT_FIELD(KTHREAD, 0x104, ULONG, Spare0)
//C_ASSERT_FIELD(KTHREAD, 0x108, KWAIT_BLOCK, WaitBlock) // type is KWAITBLOCK[4]
//C_ASSERT_FIELD(KTHREAD, 0x108, UCHAR, WaitBlockFill4) // type is UCHAR[44]
C_ASSERT_FIELD(KTHREAD, 0x134, ULONG, ContextSwitches)
//(KTHREAD, 0x108, UCHAR, WaitBlockFill5) // type is UCHAR[92]
C_ASSERT_FIELD(KTHREAD, 0x164, UCHAR, State)
C_ASSERT_FIELD(KTHREAD, 0x165, CHAR, NpxState)
C_ASSERT_FIELD(KTHREAD, 0x166, UCHAR, WaitIrql)
C_ASSERT_FIELD(KTHREAD, 0x167, CHAR, WaitMode)
//C_ASSERT_FIELD(KTHREAD, 0x108, UCHAR, WaitBlockFill6) // type is UCHAR[140]
C_ASSERT_FIELD(KTHREAD, 0x194, ULONG, WaitTime)
//C_ASSERT_FIELD(KTHREAD, 0x108, UCHAR, WaitBlockFill7)
C_ASSERT_FIELD(KTHREAD, 0x1B0, PVOID, TebMappedLowVa)
C_ASSERT_FIELD(KTHREAD, 0x1B8, struct _UMS_CONTROL_BLOCK*, Ucb)
//C_ASSERT_FIELD(KTHREAD, 0x108, UCHAR, WaitBlockFill8)
C_ASSERT_FIELD(KTHREAD, 0x1C4, SHORT, KernelApcDisable)
C_ASSERT_FIELD(KTHREAD, 0x1C6, SHORT, SpecialApcDisable)
C_ASSERT_FIELD(KTHREAD, 0x1C4, ULONG, CombinedApcDisable)
C_ASSERT_FIELD(KTHREAD, 0x1C8, LIST_ENTRY, QueueListEntry)
C_ASSERT_FIELD(KTHREAD, 0x1D8, PKTRAP_FRAME, TrapFrame)
C_ASSERT_FIELD(KTHREAD, 0x1E0, PVOID, FirstArgument)
C_ASSERT_FIELD(KTHREAD, 0x1E8, PVOID, CallbackStack)
C_ASSERT_FIELD(KTHREAD, 0x1E8, ULONG64, CallbackDepth)
C_ASSERT_FIELD(KTHREAD, 0x1F0, UCHAR, ApcStateIndex)
C_ASSERT_FIELD(KTHREAD, 0x1F1, CHAR, BasePriority)
C_ASSERT_FIELD(KTHREAD, 0x1F2, CHAR, PriorityDecrement)
C_ASSERT_FIELD(KTHREAD, 0x1F3, UCHAR, Preempted)
C_ASSERT_FIELD(KTHREAD, 0x1F4, UCHAR, AdjustReason)
C_ASSERT_FIELD(KTHREAD, 0x1F5, CHAR, AdjustIncrement)
C_ASSERT_FIELD(KTHREAD, 0x1F6, CHAR, PreviousMode)
C_ASSERT_FIELD(KTHREAD, 0x1F7, CHAR, Saturation)
C_ASSERT_FIELD(KTHREAD, 0x1F8, ULONG, SystemCallNumber)
C_ASSERT_FIELD(KTHREAD, 0x1FC, ULONG, FreezeCount)
C_ASSERT_FIELD(KTHREAD, 0x200, GROUP_AFFINITY, UserAffinity)
C_ASSERT_FIELD(KTHREAD, 0x210, KPROCESS*, Process)
C_ASSERT_FIELD(KTHREAD, 0x218, GROUP_AFFINITY, Affinity)
C_ASSERT_FIELD(KTHREAD, 0x228, ULONG, IdealProcessor)
C_ASSERT_FIELD(KTHREAD, 0x22C, ULONG, UserIdealProcessor)
//C_ASSERT_FIELD(KTHREAD, 0x230, KAPC_STATE*, ApcStatePointer) // type is PKAPC_STATE[2]
C_ASSERT_FIELD(KTHREAD, 0x240, KAPC_STATE, SavedApcState)
//C_ASSERT_FIELD(KTHREAD, 0x240, UCHAR, SavedApcStateFill)
C_ASSERT_FIELD(KTHREAD, 0x26B, UCHAR, WaitReason)
C_ASSERT_FIELD(KTHREAD, 0x26C, CHAR, SuspendCount)
C_ASSERT_FIELD(KTHREAD, 0x26D, CHAR, Spare1)
C_ASSERT_FIELD(KTHREAD, 0x26E, UCHAR, CodePatchInProgress)
C_ASSERT_FIELD(KTHREAD, 0x270, PVOID, Win32Thread)
C_ASSERT_FIELD(KTHREAD, 0x278, PVOID, StackBase)
C_ASSERT_FIELD(KTHREAD, 0x280, KAPC, SuspendApc)
C_ASSERT_FIELD(KTHREAD, 0x280, UCHAR, SuspendApcFill0)
C_ASSERT_FIELD(KTHREAD, 0x281, UCHAR, ResourceIndex)
//C_ASSERT_FIELD(KTHREAD, 0x280, UCHAR, SuspendApcFill1)
C_ASSERT_FIELD(KTHREAD, 0x283, UCHAR, QuantumReset)
//C_ASSERT_FIELD(KTHREAD, 0x280, UCHAR, SuspendApcFill2)
C_ASSERT_FIELD(KTHREAD, 0x284, ULONG, KernelTime)
//C_ASSERT_FIELD(KTHREAD, 0x280, UCHAR, SuspendApcFill3)
C_ASSERT_FIELD(KTHREAD, 0x2C0, KPRCB*, WaitPrcb)
//C_ASSERT_FIELD(KTHREAD, 0x280, UCHAR, SuspendApcFill4)
C_ASSERT_FIELD(KTHREAD, 0x2C8, PVOID, LegoData)
//C_ASSERT_FIELD(KTHREAD, 0x280, UCHAR, SuspendApcFill5)
C_ASSERT_FIELD(KTHREAD, 0x2D3, UCHAR, LargeStack)
C_ASSERT_FIELD(KTHREAD, 0x2D4, ULONG, UserTime)
C_ASSERT_FIELD(KTHREAD, 0x2D8, KSEMAPHORE, SuspendSemaphore)
//C_ASSERT_FIELD(KTHREAD, 0x2D8, UCHAR, SuspendSemaphorefill)
C_ASSERT_FIELD(KTHREAD, 0x2F4, ULONG, SListFaultCount)
C_ASSERT_FIELD(KTHREAD, 0x2F8, LIST_ENTRY, ThreadListEntry)
C_ASSERT_FIELD(KTHREAD, 0x308, LIST_ENTRY, MutantListHead)
C_ASSERT_FIELD(KTHREAD, 0x318, PVOID, SListFaultAddress)
C_ASSERT_FIELD(KTHREAD, 0x320, LONG64, ReadOperationCount)
C_ASSERT_FIELD(KTHREAD, 0x328, LONG64, WriteOperationCount)
C_ASSERT_FIELD(KTHREAD, 0x330, LONG64, OtherOperationCount)
C_ASSERT_FIELD(KTHREAD, 0x338, LONG64, ReadTransferCount)
C_ASSERT_FIELD(KTHREAD, 0x340, LONG64, WriteTransferCount)
C_ASSERT_FIELD(KTHREAD, 0x348, LONG64, OtherTransferCount)
C_ASSERT_FIELD(KTHREAD, 0x350, KTHREAD_COUNTERS*, ThreadCounters)
C_ASSERT_FIELD(KTHREAD, 0x358, XSTATE_SAVE*, XStateSave)

/* KUSER_SHARED_DATA */
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x000, ULONG, TickCountLowDeprecated)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x004, ULONG, TickCountMultiplier)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x008, KSYSTEM_TIME, InterruptTime)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x014, KSYSTEM_TIME, SystemTime)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x020, KSYSTEM_TIME, TimeZoneBias)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x02C, USHORT, ImageNumberLow)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x02E, USHORT, ImageNumberHigh)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x030, WCHAR[260], NtSystemRoot)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x238, ULONG, MaxStackTraceDepth)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x23C, ULONG, CryptoExponent)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x240, ULONG, TimeZoneId)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x244, ULONG, LargePageMinimum)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x248, ULONG[7], Reserved2)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x264, NT_PRODUCT_TYPE, NtProductType)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x268, BOOLEAN, ProductTypeIsValid)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x26C, ULONG, NtMajorVersion)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x270, ULONG, NtMinorVersion)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x274, BOOLEAN[64], ProcessorFeatures)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2B4, ULONG, Reserved1)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2B8, ULONG, Reserved3)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2BC, ULONG, TimeSlip)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2C0, ALTERNATIVE_ARCHITECTURE_TYPE, AlternativeArchitecture)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2C4, ULONG[1], AltArchitecturePad)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2C8, LARGE_INTEGER, SystemExpirationDate)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2D0, ULONG, SuiteMask)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2D4, BOOLEAN, KdDebuggerEnabled)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2D5, UCHAR, MitigationPolicies) // NXSupportPolicy
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2D8, ULONG, ActiveConsoleId)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2DC, ULONG, DismountCount)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2E0, ULONG, ComPlusPackage)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2E4, ULONG, LastSystemRITEventTickCount)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2E8, ULONG, NumberOfPhysicalPages)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2EC, BOOLEAN, SafeBootMode)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2ED, UCHAR, TscQpcData)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2EE, UCHAR[2], TscQpcPad)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2F0, ULONG, SharedDataFlags)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2F4, ULONG[1], DataFlagsPad)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x2F8, ULONGLONG, TestRetInstruction)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x300, ULONG, SystemCall)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x304, ULONG, SystemCallReturn)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x308, ULONGLONG[3], SystemCallPad)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x320, KSYSTEM_TIME, TickCount)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x320, ULONGLONG, TickCountQuad)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x320, ULONG[3], ReservedTickCountOverlay)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x32C, ULONG[1], TickCountPad)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x330, ULONG, Cookie)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x334, ULONG[1], CookiePad)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x338, ULONGLONG, ConsoleSessionForegroundProcessId)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x340, ULONG[16], DEPRECATED_Wow64SharedInformation)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x380, USHORT[16], UserModeGlobalLogger)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x3A0, ULONG, ImageFileExecutionOptions)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x3A4, ULONG, LangGenerationCount)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x3A8, ULONGLONG, Reserved5)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x3B0, ULONGLONG, InterruptTimeBias)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x3B8, ULONGLONG, QpcBias) // TscQpcBias
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x3C0, ULONG, ActiveProcessorCount)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x3C4, USHORT, ActiveGroupCount)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x3C6, USHORT, Reserved4)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x3C8, ULONG, AitSamplingValue)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x3CC, ULONG, AppCompatFlag)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x3D0, ULONGLONG, SystemDllNativeRelocation)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x3D8, ULONG, SystemDllWowRelocation)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x3DC, ULONG[1], XStatePad)
C_ASSERT_FIELD(KUSER_SHARED_DATA, 0x3E0, XSTATE_CONFIGURATION, XState)
