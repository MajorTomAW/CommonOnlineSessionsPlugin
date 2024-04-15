// Copyright © 2024 MajorT. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class CommonSessionsPluginTarget : TargetRules
{
	public CommonSessionsPluginTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "CommonSessionsPlugin" } );
	}
}
