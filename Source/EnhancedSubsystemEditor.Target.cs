// Copyright © 2024 MajorT. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class EnhancedSubsystemEditorTarget : TargetRules
{
	public EnhancedSubsystemEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "EnhancedSubsystem" } );
	}
}
