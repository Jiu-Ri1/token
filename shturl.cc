<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>金融合规智能审查 Agent</title>
    <script src="https://cdn.tailwindcss.com"></script>
    <link href="https://cdn.jsdelivr.net/npm/font-awesome@4.7.0/css/font-awesome.min.css" rel="stylesheet">
    <script>
        tailwind.config = {
            theme: {
                extend: {
                    colors: {
                        primary: '#165DFF',
                        secondary: '#0D2B94',
                        success: '#00B42A',
                        warning: '#FF7D00',
                        danger: '#F53F3F',
                        dark: '#0F172A',
                    },
                }
            }
        }
    </script>
    <style>
        * { font-family: system-ui, sans-serif; }
        .glass { background: rgba(255,255,255,0.9); backdrop-filter: blur(10px); }
        .card-hover { transition: all 0.3s; }
        .card-hover:hover { transform: translateY(-4px); box-shadow: 0 20px 40px rgba(22,93,255,0.1); }
        .gradient-bg { background: linear-gradient(135deg, #165DFF 0%, #0D2B94 100%); }
    </style>
</head>
<body class="bg-slate-50">
<div class="sticky top-0 z-50">
    <div class="glass px-6 py-4 border-b border-slate-200">
        <div class="max-w-7xl mx-auto flex justify-between items-center">
            <div class="flex items-center gap-3">
                <div class="gradient-bg text-white p-2 rounded-lg shadow-lg"><i class="fa fa-shield text-xl"></i></div>
                <h1 class="text-xl font-bold text-slate-800">金融合规智能审查 Agent 系统</h1>
            </div>
            <div class="text-sm text-slate-500 bg-primary/5 px-3 py-1.5 rounded-full">每日 Token 消耗：<b class="text-primary">400万</b></div>
        </div>
    </div>
</div>
<div class="max-w-7xl mx-auto px-4 py-10">
    <div class="gradient-bg rounded-2xl shadow-xl p-8 text-white mb-8">
        <h2 class="text-2xl font-bold mb-3">多 Agent 智能合规审查 · 企业级解决方案</h2>
        <p class="text-white/90 text-lg">自动识别合同风险、完成监管合规校验、生成专业审查报告，将人工审查从 4 小时缩短至 10 分钟。</p>
        <div class="flex flex-wrap gap-2 mt-5">
            <span class="bg-white/20 px-3 py-1 rounded-full text-sm">文件解析 Agent</span>
            <span class="bg-white/20 px-3 py-1 rounded-full text-sm">规则校验 Agent</span>
            <span class="bg-white/20 px-3 py-1 rounded-full text-sm">风险定级 Agent</span>
            <span class="bg-white/20 px-3 py-1 rounded-full text-sm">报告生成 Agent</span>
        </div>
    </div>
    <div class="grid grid-cols-1 lg:grid-cols-3 gap-8">
        <div class="lg:col-span-2 bg-white rounded-2xl shadow-md p-6 card-hover">
            <h3 class="text-lg font-semibold flex items-center gap-2 mb-4"><i class="fa fa-file-text-o text-primary"></i>合同内容审查</h3>
            <textarea id="contractText" class="w-full h-56 p-4 border border-slate-200 rounded-xl text-slate-700 focus:ring-2 focus:ring-primary/30 focus:border-primary outline-none" placeholder="请粘贴合同文本"></textarea>
            <div class="flex gap-3 mt-5">
                <button onclick="startAnalyze()" class="gradient-bg text-white px-6 py-3 rounded-xl hover:shadow-lg">启动智能审查</button>
                <button onclick="loadDemoText()" class="bg-slate-100 text-slate-700 px-5 py-3 rounded-xl">加载示例合同</button>
            </div>
        </div>
        <div class="bg-white rounded-2xl shadow-md p-6 card-hover">
            <h3 class="text-lg font-semibold flex items-center gap-2 mb-5"><i class="fa fa-bar-chart text-primary"></i>审查结果</h3>
            <div id="emptyState" class="h-64 flex flex-col items-center justify-center text-slate-400"><i class="fa fa-inbox text-4xl mb-3"></i><p>请点击「启动智能审查」</p></div>
            <div id="resultPanel" class="hidden space-y-5">
                <div><div class="flex justify-between text-sm mb-1.5"><span>合规评分</span><span id="scoreNum" class="font-semibold text-warning">58</span></div><div class="h-2 w-full bg-slate-100 rounded-full"><div id="scoreBar" class="h-full rounded-full gradient-bg" style="width:58%"></div></div></div>
                <div class="grid grid-cols-2 gap-3 text-sm"><div class="bg-danger/5 p-3 rounded-xl"><p class="text-danger font-medium">高风险</p><p id="highNum" class="text-xl font-bold">2</p></div><div class="bg-warning/5 p-3 rounded-xl"><p class="text-warning font-medium">中风险</p><p id="midNum" class="text-xl font-bold">1</p></div></div>
                <div class="text-slate-500 text-sm">审查耗时：<span id="timeUse">8.2s</span></div>
            </div>
        </div>
    </div>
    <div class="mt-8 bg-white rounded-2xl shadow-md p-6 card-hover">
        <h3 class="text-lg font-semibold flex items-center gap-2 mb-5"><i class="fa fa-cogs text-primary"></i>多 Agent 协作推理链</h3>
        <div id="flowEmpty" class="h-16 flex items-center justify-center text-slate-400">等待执行…</div>
        <div id="flowSteps" class="hidden space-y-4">
            <div class="flex gap-4"><div class="w-7 h-7 rounded-full bg-primary/15 text-primary flex items-center justify-center"><i class="fa fa-file-text-o"></i></div><div><b>文件解析 Agent</b>：已完成合同拆分、条款提取</div></div>
            <div class="flex gap-4"><div class="w-7 h-7 rounded-full bg-primary/15 text-primary flex items-center justify-center"><i class="fa fa-check-square-o"></i></div><div><b>规则校验 Agent</b>：完成监管规则匹配</div></div>
            <div class="flex gap-4"><div class="w-7 h-7 rounded-full bg-primary/15 text-primary flex items-center justify-center"><i class="fa fa-exclamation-triangle"></i></div><div><b>风险定级 Agent</b>：完成风险判定</div></div>
            <div class="flex gap-4"><div class="w-7 h-7 rounded-full bg-primary/15 text-primary flex items-center justify-center"><i class="fa fa-file-pdf-o"></i></div><div><b>报告生成 Agent</b>：已生成审查报告</div></div>
        </div>
    </div>
    <div class="mt-8 bg-white rounded-2xl shadow-md p-6 card-hover">
        <h3 class="text-lg font-semibold flex items-center gap-2 mb-5"><i class="fa fa-shield text-primary"></i>风险条款详情</h3>
        <div id="riskEmpty" class="h-16 flex items-center justify-center text-slate-400">暂无风险数据</div>
        <div id="riskList" class="hidden space-y-3">
            <div class="p-4 border border-danger/20 bg-danger/5 rounded-xl"><div class="font-medium text-danger">高风险：免除自身法定责任</div><div class="text-sm text-slate-600">甲方承诺向乙方提供资金服务，但不承担任何风险责任，所有损失由乙方自行承担。</div></div>
            <div class="p-4 border border-danger/20 bg-danger/5 rounded-xl"><div class="font-medium text-danger">高风险：限制投诉权利</div><div class="text-sm text-slate-600">乙方不得向监管机构投诉，否则视为违约。</div></div>
            <div class="p-4 border border-warning/20 bg-warning/5 rounded-xl"><div class="font-medium text-warning">中风险：不公平最终解释权</div><div class="text-sm text-slate-600">本合同最终解释权归甲方所有。</div></div>
        </div>
    </div>
    <div class="mt-8 bg-gradient-to-br from-primary/5 to-secondary/5 rounded-2xl p-8 text-center">
        <h3 class="text-xl font-bold mb-2">审查报告已生成</h3>
        <p class="text-slate-500 mb-5">可直接用于审批、归档、法务复核</p>
        <button id="downloadBtn" disabled class="bg-slate-300 text-slate-500 px-8 py-3 rounded-xl cursor-not-allowed"><i class="fa fa-download mr-1"></i>下载正式报告</button>
    </div>
</div>
<script>
    function loadDemoText(){document.getElementById('contractText').value="甲方承诺向乙方提供资金服务，但不承担任何风险责任，所有损失由乙方自行承担。\n乙方不得向监管机构投诉，否则视为违约。\n本合同最终解释权归甲方所有。";}
    function startAnalyze(){
        document.getElementById('emptyState').classList.add('hidden');
        document.getElementById('flowEmpty').classList.add('hidden');
        document.getElementById('riskEmpty').classList.add('hidden');
        setTimeout(()=>{
            document.getElementById('resultPanel').classList.remove('hidden');
            document.getElementById('flowSteps').classList.remove('hidden');
            document.getElementById('riskList').classList.remove('hidden');
            const btn=document.getElementById('downloadBtn');
            btn.classList.remove('bg-slate-300','cursor-not-allowed');
            btn.classList.add('gradient-bg','text-white');
            btn.disabled=false;
        },1300);
    }
</script>
</body>
</html>
